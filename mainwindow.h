#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QPoint>
#include <QColor>
#include <QPen>
#include <QObject>
#include <QEvent>
#include <QFont>
#include <QWheelEvent>
#include <QStringListModel>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include <QTextCodec>

#include <iostream>
#include <stdlib.h>
#include <cstring>

#include "map.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    static const int widget_h = 531;
    static const int widget_l = 671;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Map* world_main;
    Map* hell;
    Map* the_end;

    Map* world;

    int selected_id = -2;
    int selected_world = 1;

    void updateListView(Map* w);

private:
    Ui::MainWindow *ui;
    int coordinate_x;
    int coordinate_z;

protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void widget1Paint(QPoint* mouse_pos);   //主世界地图绘制
    void widget2Paint(QPoint* mouse_pos);   //地狱地图绘制
    void widget3Paint(QPoint* mouse_pos);   //末地地图绘制
    void setMouseCoordinate(double x , double z); //获取鼠标在世界坐标系中的位置
    QPoint* getMouseCoordinate(); //获取鼠标在世界坐标系中的位置\




private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_listView_clicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_2_clicked();
    void on_listView_2_clicked(const QModelIndex &index);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_tabWidget_currentChanged(int index);
};

#endif // MAINWINDOW_H
