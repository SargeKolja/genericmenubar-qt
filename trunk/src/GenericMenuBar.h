#ifndef GENERICMENUBAR_H
#define GENERICMENUBAR_H

/**
 * Project "GenericMenuBar for Qt"
 *
 * GenericMenuBar.h
 * 
 * Just want to have a button bar, instead of a classic File-Edit-...-Help Menu bar?
 * Want to start with Qt, and like to work together, bring your ideas and code?
 *
 * You are welcome, here we go!
 *
 * This is a simplified implementation of a Widget (sub window) which
 * can reside at the side, top or bottom of your application and show some buttons or Icons or Images (QPixmap),
 * touchable/clickable and grouped together.
  *
 * Also want to have this?
 *
 * Plans:
 * a lot
 * 
 * copyright 2019 Sergeant Kolja, GERMANY
 * 
 * distributed under the terms of the 2-clause license also known as "Simplified BSD License" or "FreeBSD License"
 * License is compatible with GPL and LGPL
 */ 


#include <QWidget>
#include <QGroupBox>
#include <QLayout>
#include <QPushButton>
#include <QIcon>
#include <QImage>
#include <QLabel>

class GenericMenuBar : public QWidget
{
  Q_OBJECT
public:
  explicit GenericMenuBar( Qt::Orientation orientation, QWidget *parent = nullptr);
  virtual ~GenericMenuBar();
  void addWidget( QWidget* pButtonOrLabelOrPixMap );
  void addWidget( QWidget& rButtonOrLabelOrPixMap );
  void addStretch( int size );
signals:

public slots:

private:
   Qt::Orientation mOrientation;
   QGroupBox       mGroupFrame;
   QBoxLayout      mMenuLayout, mOuterLayout;
#if defined INCLUDE_TEST_WIDGETS_INTO_MENU
   QPushButton     mButton1, mButtonHoldingIcon;
   QLabel          mLabel1, mLabelHoldingImage;
   QIcon           mIconOnButton;
   QPixmap         mImageOnLabel;
#endif //defined INCLUDE_TEST_WIDGETS_INTO_MENU
};




class GenericHMenuBar : public GenericMenuBar
{
  Q_OBJECT
public:
  explicit GenericHMenuBar( QWidget *parent = nullptr) : GenericMenuBar( Qt::Horizontal, parent ) {}
};


class GenericVMenuBar : public GenericMenuBar
{
  Q_OBJECT
public:
  explicit GenericVMenuBar( QWidget *parent = nullptr) : GenericMenuBar( Qt::Vertical, parent ) {}
};


#endif // GENERICMENUBAR_H
