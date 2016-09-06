#ifndef PROJECTLISTWIDGET_H
#define PROJECTLISTWIDGET_H

#include <QListWidget>
#include <QWidget>

class projectlistwidget : public QListWidget
{
public:
    projectlistwidget(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void performDrag();

    QPoint startPos;
};

#endif // PROJECTLISTWIDGET_H
