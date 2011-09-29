#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractButton>
#include <QDebug>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMainWindow>
#include <QSignalMapper>

#include <kstatusnotifieritem.h>
#include <kmenu.h>

#include "src/dropboxclient.h"
#include "src/dropboxclientadaptor.h"
#include "src/configuration.h"
#include "src/configurationdbdriver.h"
#include "src/installerform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent* e);

private:
    void loadSettings();
    void initializeDBus();
    QString fixUnicodeChars(const QString& value);
    QString resolveFileName(const QString& filename);

    Ui::MainWindow* ui;
    DropboxClient* dc;
    DropboxClientAdaptor* adaptor;

    QSignalMapper* sm;
    KStatusNotifierItem* trayIcon;

    QIcon defaultIcon;
    QIcon idleIcon;
    QIcon bussyIcon;
    QIcon errorIcon;
    QIcon appIcon;

    QStringList* iconsetList;

    QAction *openDropboxWebsite;
    QAction *action0;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *statusAction;
    QAction *openHelpCenter;
    QAction *openTour;
    QAction *openForums;
    QAction *openGetMoreSpace;
    QAction *openPrefs;
    QAction *startAction;
    QAction *stopAction;
    QAction *openDir;
    KMenu *trayIconMenu;
    QMenu *chFiles;
    QMenu *helpMenu;

public slots:
    void applySettings();
    void dialogButtonBoxTriggered(QAbstractButton* button);
    void changeDropboxFolder();
    void loadIcons(const QString &iconset=QString());
    void downloadRadioToggle();
    void uploadRadioToggle();
    void proxyRadioToggle();
    void proxyAuthRadioToggle();

    void updateStatus(DropboxStatus newStatus, const QString &message);

    void openFileBrowser(const QString &path="");
    void openHelpCenterURL();
    void openTourURL();
    void openForumsURL();
    void openDropboxWebsiteURL();
    void openGetMoreSpaceURL();
    void prepareLastChangedFiles();
};

#endif // MAINWINDOW_H
