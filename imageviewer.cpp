#include "imageviewer.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent)
{
    mViewImage = new QLabel;
    QLabel *lLineLabel = new QLabel("Please enter the path of image:");
    mPathImage = new QLineEdit;
    QPushButton *lButtonDownload = new QPushButton("Download");

    QHBoxLayout *lHBoxImage = new QHBoxLayout;
    QHBoxLayout *lHBoxPath = new QHBoxLayout;
    QVBoxLayout *lVBoxImage = new QVBoxLayout;

    lHBoxImage -> addWidget(mViewImage);
    lHBoxPath -> addWidget(lLineLabel);
    lHBoxPath -> addWidget(mPathImage);
    lHBoxPath -> addWidget(lButtonDownload);

    lVBoxImage -> addLayout(lHBoxImage);
    lVBoxImage -> addLayout(lHBoxPath);

    setGeometry(200, 200, 700, 50);
    setLayout(lVBoxImage);
    setWindowTitle("Image viewer");

    connect(lButtonDownload, SIGNAL(clicked()), this, SLOT(downloadImage()));
}

void ImageViewer::downloadImage()
{
    QString path;
    QPixmap lImage;

    path= mPathImage -> text();

    if (lImage.load(path))
    {
        mViewImage -> setPixmap(lImage);
    }
    else
    {
        mViewImage -> setText("Can't open image");
    }
}
