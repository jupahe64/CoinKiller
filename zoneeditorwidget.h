#ifndef ZONEEDITORWIDGET_H
#define ZONEEDITORWIDGET_H

#include "objects.h"
#include "settingsmanager.h"

#include <QWidget>
#include <QListWidget>
#include <QFrame>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>
#include <QScrollArea>
#include <QCheckBox>
#include <QPushButton>

class BgPreview : public QLabel
{
    Q_OBJECT
public:
    BgPreview();
    void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE;
    void setBg(QPixmap bg);
private:
    QPixmap bg;
};

class ZoneEditorWidget : public QWidget
{
    Q_OBJECT
public:
    ZoneEditorWidget(QList<Zone*> *zones);
    void deselect();
    void select(Zone* zone);
    void updateEditor();

signals:
    void updateLevelView();
    void selectedZoneChanged(Object* zone);
    void selectZoneContents(Zone* zone);
    void editMade();
    void screenshot(QRect);

private:
    QListWidget* zoneList;

    QTabWidget* settingsTabs;

    QPushButton* selectContentsBtn;
    QPushButton* screenshotBtn;

    QSpinBox* id;
    QComboBox* multiplayerTracking;
    QMap<int, QString> multiplayerTrackings;
    QSpinBox* progPathId;
    QComboBox* musicId;
    QMap<int, QString> musicIds;
    QSpinBox* unk1;

    QComboBox* background;
    QMap<QString, QString> backgrounds;
    BgPreview* backgroundPreview;
    QSpinBox* bgXPos;
    QSpinBox* bgYPos;
    QSpinBox* bgUnk1;

    QSpinBox* upperBound;
    QSpinBox* lowerBound;
    QSpinBox* unkUpperBound;
    QSpinBox* unkLowerBound;
    QCheckBox* upScrolling;

    QWidget* generalTab;
    QWidget* boundsTab;
    QWidget* backgroundTab;

    QList<Zone*> *zones;
    Zone* editZone;

    class HorLine : public QFrame { public: HorLine() { setFrameStyle(QFrame::HLine | QFrame::Sunken); } };

    void loadMusicIDs();
    void loadBackgrounds();

    void updateList();
    void updateInfo();
    void updateBgPreview();

    bool editingAZone = false;
    bool handleChanges = true;

private slots:
    void handleZoneListIndexChange(QListWidgetItem* item);
    void handleIDChange(int idVal);
    void handleProgPathIDChange(int ppIDVal);
    void handleMusicIDChange(QString text);
    void handleMultiPlayerTrackingChange(QString text);
    void handleUnk1Change(int val);
    void handleUpScrollingChange(bool val);
    void handleUpperBoundChange(int val);
    void handleLowerBoundChange(int val);
    void handleUnkUpperBoundChange(int val);
    void handleUnkLowerBoundChange(int val);
    void handleBackgroundChange(QString text);
    void handleBgUnk1Change(int val);
    void handleBgXPosChanged(int val);
    void handleBgYPosChanged(int val);
    void handleSelectContentsClicked();
    void handleScreenshotClicked();
};

#endif // ZONEEDITORWIDGET_H
