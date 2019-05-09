#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QRect>
#include <QDesktopWidget>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QDebug>

class mainwindow : public QWidget {
public:
  mainwindow();

private:

  void add_acts();
  void add_menus();
  void action_definations();

  QAction users,about_us;
  QAction *exit_program = new QAction();

  QMenu *file = new QMenu("File");
  QMenu *help = new QMenu("Help");
  QMenuBar *menubar = new QMenuBar();
  QGridLayout *primarylayout = new QGridLayout();


signals:
    void about();

public slots:
    void launch_about();
};

#endif // MAINWINDOW_H
