#ifndef _STREAM_CONFIG_DIALOG_H
#define _STREAM_CONFIG_DIALOG_H

#include <QDialog>
#include "ui_streamconfigdialog.h"
#include "stream.h"
#include "packetmodel.h"
#include "modeltest.h"

#define MAX_MAC_ITER_COUNT	256
#define MIN_PKT_LEN			64
#define MAX_PKT_LEN			1522

/*
** TODO
** - Improve HexStr handling
**
*/

class StreamConfigDialog : public QDialog, public Ui::StreamConfigDialog
{
	Q_OBJECT
public:
	StreamConfigDialog(QList<Stream> *streamList, uint streamIndex, 
		QWidget *parent = 0);
	~StreamConfigDialog();

private: 
	QList<Stream>	*mpStreamList;
	uint			mCurrentStreamIndex;
	PacketModel		*mpPacketModel;
	ModelTest		*mpPacketModelTester;

	void setupUiExtra();
	void LoadCurrentStream();
	void StoreCurrentStream();

private slots:
	void on_cmbDstMacMode_currentIndexChanged(QString mode);
	void on_pbPrev_clicked();
	void on_pbNext_clicked();

	void on_rbFtLlcSnap_toggled(bool checked);

	void on_rbL3Ipv4_toggled(bool checked);
	void on_rbL3Arp_toggled(bool checked);

	void on_rbL4Icmp_toggled(bool checked);
	void on_rbL4Igmp_toggled(bool checked);
	void on_rbL4Tcp_toggled(bool checked);
	void on_rbL4Udp_toggled(bool checked);
	void on_rbL4Other_toggled(bool checked);

	void update_NumPacketsAndNumBursts();

	void on_pbOk_clicked();
};

QString & uintToHexStr(quint32 num, QString &hexStr, quint8 octets);

#endif
