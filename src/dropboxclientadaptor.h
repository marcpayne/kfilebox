#ifndef DROPBOXCLIENTADAPTOR_H
#define DROPBOXCLIENTADAPTOR_H

#include <QByteArray>
#include <QList>
#include <QMap>
#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QtDBus>
#include <QVariant>

#include "src/dropboxclient.h" //! for DropboxClient::DropboxStatus

class DropboxClientAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "org.kde.Kfilebox")
	Q_CLASSINFO("D-Bus Introspection", ""
				"  <interface name=\"org.kde.Kfilebox\">\n"
				"    <method name=\"start\"/>\n"
				"    <method name=\"stop\"/>\n"
				"    <signal name=\"update_status\">\n"
				"        <arg name=\"state\" type=\"i\" direction=\"out\"/>\n"
				"        <arg name=\"message\" type=\"s\" direction=\"out\"/>\n"
				"    </signal>\n"
				"    <method name=\"get_public_link\">\n"
				"        <arg name=\"filename\" type=\"s\" direction=\"in\" />\n"
				"        <arg type=\"s\" direction=\"out\" />\n"
				"    </method>\n"
				"    <method name=\"send_command\">\n"
				"        <arg name=\"arg\" type=\"s\" direction=\"in\" />\n"
				"        <arg type=\"s\" direction=\"out\" />\n"
				"    </method>\n"
				"  </interface>\n"
				"")
public:
	DropboxClientAdaptor(DropboxClient *parent);
    virtual ~DropboxClientAdaptor();

public:
public Q_SLOTS:
    void start();
    void stop();
	QString get_public_link(const QString& filename);
	QString send_command(const QString& arg);
	QString get_status_message();
	QString get_version();
	QStringList get_shared_folders();
//	QStringList get_recently_changed();
	QString get_auth_url();

Q_SIGNALS:
	void update_status(DropboxStatus, QString);
};

#endif // DROPBOXCLIENTADAPTOR_H
