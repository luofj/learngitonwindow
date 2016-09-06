#include "projectlistwidget.h"
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPoint>
#include <QApplication>
#include <QListWidgetItem>
#include <QMimeData>
#include <QDrag>
#include <QPixmap>

projectlistwidget::projectlistwidget(QWidget *parent)
    :QListWidget(parent)
{
   setAcceptDrops(true);
}

void projectlistwidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        startPos = event->pos();
    QListWidget::mousePressEvent(event);
}

void projectlistwidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        int distance = (event->pos() - startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance()){
           performDrag();
        }
    }
    QListWidget::mouseMoveEvent(event);
}

void projectlistwidget::performDrag(){
    QListWidgetItem *item = currentItem();
    if (item) {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/images/person.png"));
        if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
            delete item;
    }
}

void projectlistwidget::dragEnterEvent(QDragEnterEvent *event){
    projectlistwidget *source = qobject_cast<projectlistwidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void projectlistwidget::dragMoveEvent(QDragMoveEvent *event){
    projectlistwidget *source = qobject_cast<projectlistwidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void projectlistwidget::dropEvent(QDropEvent *event){
    projectlistwidget *source = qobject_cast<projectlistwidget *>(event->source());
    if (source && source != this) {
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}


