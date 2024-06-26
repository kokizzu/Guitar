#ifndef REPOSITORYWRAPPERFRAME_H
#define REPOSITORYWRAPPERFRAME_H

#include "BranchLabel.h"
#include "Git.h"
#include "GitObjectManager.h"

#include <QFrame>
#include <mutex>

class MainWindow;
class LogTableWidget;
class FileListWidget;
class FileDiffWidget;

class RepositoryWrapperFrame : public QFrame {
	Q_OBJECT
	friend class MainWindow;
private:
	
	mutable std::mutex commit_log_mutex;
	
	Git::CommitItemList commit_log;

	MainWindow *mw_ = nullptr;
	LogTableWidget *logtablewidget_ = nullptr;
	FileListWidget *filelistwidget_ = nullptr;
	FileListWidget *unstagedfilelistwidget_ = nullptr;
	FileListWidget *stagesfilelistwidget_ = nullptr;
	FileDiffWidget *filediffwidget_ = nullptr;

	std::map<Git::CommitID, QList<Git::Branch>> branch_map;
	std::map<Git::CommitID, QList<Git::Tag>> tag_map;
	std::map<int, QList<BranchLabel>> label_map;
	std::map<QString, Git::Diff> diff_cache;

	GitObjectCache objcache;

	MainWindow *mainwindow();
	MainWindow const *mainwindow() const;
public:
	explicit RepositoryWrapperFrame(QWidget *parent = nullptr);
	~RepositoryWrapperFrame() override;
	Git::CommitItem commitItem(int row) const;
	QIcon signatureVerificationIcon(const Git::CommitID &id) const;
	QImage committerIcon(int row, QSize size) const;
	const QList<BranchLabel> *label(int row) const;
	QString currentBranchName() const;
	Git::CommitItemList getLogs() const;
	bool isAncestorCommit(const QString &id);
	QColor color(unsigned int i);
	void updateAncestorCommitMap();
	void bind(MainWindow *mw
			  , LogTableWidget *logtablewidget
			  , FileListWidget *filelistwidget
			  , FileListWidget *unstagedfilelistwidget
			  , FileListWidget *stagesfilelistwidget
			  , FileDiffWidget *filediffwidget
			  );

	void prepareLogTableWidget();
	void clearLogContents();
	LogTableWidget *logtablewidget();
	FileListWidget *filelistwidget();
	FileListWidget *unstagedFileslistwidget();
	FileDiffWidget *filediffwidget();
	FileListWidget *stagedFileslistwidget();
	void updateLogTableView();
	void setFocusToLogTable();
	void selectLogTableRow(int row);
public slots:
	void avatarReady();
};

struct RepositoryWrapperFrameP {
	RepositoryWrapperFrame *pointer;
	RepositoryWrapperFrameP(RepositoryWrapperFrame *pointer = nullptr)
		: pointer(pointer)
	{
	}
};

#endif // REPOSITORYWRAPPERFRAME_H
