#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QString;
class QTextEdit;
class QDragEnterEvent;
class QDropEvent;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private:
    bool readFile(const QString &fileName);
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
