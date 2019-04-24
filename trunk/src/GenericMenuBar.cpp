/**
 * Project "GenericMenuBar for Qt"
 *
 * GenericMenuBar.cpp
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
#include "GenericMenuBar.h"

#include <QPixmap>

GenericMenuBar::GenericMenuBar(Qt::Orientation orientation, QWidget *parent )
  : QWidget(parent)
  , mGroupFrame( /*"Main Menu",*/ this )
  , mMenuLayout( (orientation==Qt::Horizontal) ? QBoxLayout::LeftToRight : QBoxLayout::TopToBottom )
  , mOuterLayout((orientation==Qt::Horizontal) ? QBoxLayout::LeftToRight : QBoxLayout::TopToBottom )
  #if defined INCLUDE_TEST_WIDGETS_INTO_MENU
  , mButton1( /*no icon,*/ "Button 1", this )
  , mButtonHoldingIcon(this)
  , mLabel1( "Label 1", this )
  , mLabelHoldingImage(this)
  , mIconOnButton( ":/SampleIcon1.jpg" )
  , mImageOnLabel( ":/SampleImage1.png" )
  #endif //defined INCLUDE_TEST_WIDGETS_INTO_MENU
{
  mOuterLayout.setMargin( 0 ); // margin (Einrueckung) zum group frame: 0
  mOuterLayout.setSpacing(0 ); // hier egal: Abstand zwischen dem einen Groupbox-Rahmen
  mOuterLayout.setContentsMargins( QMargins(0,0,0,0) );  // Abstand des Groupbox-Rahmens zum umschliessenden Bereich

  //mGroupFrame.setCheckable(true);
  mGroupFrame.setChecked(true);
  mGroupFrame.setLayout( &mMenuLayout );

  mMenuLayout.setMargin( 0  ); // Abstand zum QGroupFrame
  mMenuLayout.setSpacing( 8 ); // Abstand zwischen den Buttons
  // By default, QLayout uses the values provided by the style. On most platforms, the margin is 11 pixels in all directions. I don't wat it here
  mMenuLayout.setContentsMargins( QMargins(3,3,3,3) );  // Sets the left, top, right, and bottom margins to use around the layout.

#if defined INCLUDE_TEST_WIDGETS_INTO_MENU
  // ------- static png image ------------
  //mLabelHoldingImage.setPixmap( QPixmap::fromImage( mImageOnLabel ) );
  mLabelHoldingImage.setMinimumSize(  64, 64 );
  mLabelHoldingImage.setMaximumSize( 256,256 );
  mLabelHoldingImage.setPixmap( mImageOnLabel.scaled( 128,128, Qt::KeepAspectRatio ) );
  mLabelHoldingImage.updateGeometry();
  mMenuLayout.addWidget( &mLabelHoldingImage );
  // ------- static label ------------
  // mLabel1.setMinimumSize( 48, 48 );
  // mLabel1.setMaximumSize( 64, 64 );
  mMenuLayout.addWidget( &mLabel1 );
  // ------- button ------------
  // mButton1.setMinimumSize( 48, 48 );
  // mButton1.setMaximumSize( 128, 128 );
  // mButton1.updateGeometry();
  mMenuLayout.addWidget( &mButton1 );
  // ------- static icon ------------
  mButtonHoldingIcon.setIcon( mIconOnButton );
  //mButtonHoldingIcon.setMinimumSize( 48, 32 );
  //mButtonHoldingIcon.setMaximumSize( 64, 64 );
  mButtonHoldingIcon.updateGeometry();
  mMenuLayout.addWidget( &mButtonHoldingIcon );
  // ------- stretch the end, so all items are stciky to each other ------------
  //mMenuLayout.addStretch(1);

  //mGroupFrame.updateGeometry();
#endif // defined INCLUDE_TEST_WIDGETS_INTO_MENU
  mGroupFrame.setGeometry(1,1,10,10);
  mGroupFrame.adjustSize();

  mOuterLayout.addWidget( &mGroupFrame );
  this->setLayout( &mOuterLayout );
}


GenericMenuBar::~GenericMenuBar()
{
  // maybe cleanup and delete layout is required here?
}

void GenericMenuBar::addWidget(QWidget& rButtonOrLabelOrPixMap)
{
  mMenuLayout.addWidget( &rButtonOrLabelOrPixMap );
  mGroupFrame.adjustSize();
}

void GenericMenuBar::addWidget(QWidget* pButtonOrLabelOrPixMap)
{
  mMenuLayout.addWidget( pButtonOrLabelOrPixMap );
  mGroupFrame.adjustSize();
}

void GenericMenuBar::addStretch(int size)
{
  // ------- stretch the end, so all items are stciky to each other ------------
  mMenuLayout.addStretch(size);
}

