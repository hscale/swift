#ifndef SWIFT_QtMainWindow_H
#define SWIFT_QtMainWindow_H

#include <QWidget>
#include <QMenu>
#include "Swift/Controllers/MainWindow.h"
#include "Swift/QtUI/QtRosterHeader.h"
#include "Swift/QtUI/EventViewer/QtEventWindow.h"

#include <vector>

class QComboBox;
class QLineEdit;
class QPushButton;
class QToolBar;
class QAction;

class QTabWidget;

namespace Swift {
	class QtTreeWidget;
	class QtTreeWidgetFactory;
	class TreeWidget;
	class UIEventStream;
	class QtTabWidget;

	class QtMainWindow : public QWidget, public MainWindow {
		Q_OBJECT
		public:
			QtMainWindow(UIEventStream* eventStream, QtTreeWidgetFactory *treeWidgetFactory);
			TreeWidget* getTreeWidget();
			std::vector<QMenu*> getMenus() {return menus_;}
			void setMyName(const String& name);
			void setMyAvatarPath(const String& path);
			void setMyStatusText(const String& status);
			void setMyStatusType(const StatusShow::Type type);
			QtEventWindow* getEventWindow();
		private slots:
			void handleStatusChanged(StatusShow::Type showType, const QString &statusMessage);
			void handleShowOfflineToggled(bool);
			void handleJoinMUCAction();
			void handleSignOutAction();
			void handleJoinMUCDialogComplete(const JID& muc, const QString& nick);
			void handleAddContactDialogComplete(const JID& contact, const QString& name);
			void handleAddActionTriggered(bool checked);
			void handleEventCountUpdated(int count);
		private:
			std::vector<QMenu*> menus_;
			QLineEdit* muc_;
			QLineEdit* mucNick_;
			QPushButton* mucButton_;
			QtTreeWidget* treeWidget_;
			QtRosterHeader* meView_;
			QAction* addAction_;
			QtTabWidget* tabs_;
			QWidget* contactsTabWidget_;
			QWidget* eventsTabWidget_;
			QtEventWindow* eventWindow_;
			UIEventStream* uiEventStream_;
	};
}

#endif

