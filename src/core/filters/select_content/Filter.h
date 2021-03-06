// Copyright (C) 2019  Joseph Artsimovich <joseph.artsimovich@gmail.com>, 4lex4 <4lex49@zoho.com>
// Use of this source code is governed by the GNU GPLv3 license that can be found in the LICENSE file.

#ifndef SCANTAILOR_SELECT_CONTENT_FILTER_H_
#define SCANTAILOR_SELECT_CONTENT_FILTER_H_

#include <QCoreApplication>
#include <vector>

#include "AbstractFilter.h"
#include "FilterResult.h"
#include "NonCopyable.h"
#include "PageOrderOption.h"
#include "PageView.h"
#include "SafeDeletingQObjectPtr.h"
#include "Settings.h"
#include "intrusive_ptr.h"

class PageSelectionAccessor;
class QString;

namespace page_layout {
class Task;
class CacheDrivenTask;
}  // namespace page_layout

namespace select_content {
class OptionsWidget;
class Task;
class CacheDrivenTask;
class Settings;

class Filter : public AbstractFilter {
  DECLARE_NON_COPYABLE(Filter)

  Q_DECLARE_TR_FUNCTIONS(select_content::Filter)
 public:
  explicit Filter(const PageSelectionAccessor& pageSelectionAccessor);

  ~Filter() override;

  QString getName() const override;

  PageView getView() const override;

  int selectedPageOrder() const override;

  void selectPageOrder(int option) override;

  virtual std::vector<PageOrderOption> pageOrderOptions() const;

  void performRelinking(const AbstractRelinker& relinker) override;

  void preUpdateUI(FilterUiInterface* ui, const PageInfo& pageInfo) override;

  QDomElement saveSettings(const ProjectWriter& writer, QDomDocument& doc) const override;

  void loadSettings(const ProjectReader& reader, const QDomElement& filtersEl) override;

  void loadDefaultSettings(const PageInfo& pageInfo) override;

  intrusive_ptr<Task> createTask(const PageId& pageId,
                                 intrusive_ptr<page_layout::Task> nextTask,
                                 bool batch,
                                 bool debug);

  intrusive_ptr<CacheDrivenTask> createCacheDrivenTask(intrusive_ptr<page_layout::CacheDrivenTask> nextTask);

  OptionsWidget* optionsWidget();

 private:
  void writePageSettings(QDomDocument& doc, QDomElement& filterEl, const PageId& pageId, int numericId) const;


  intrusive_ptr<Settings> m_settings;
  SafeDeletingQObjectPtr<OptionsWidget> m_optionsWidget;
  std::vector<PageOrderOption> m_pageOrderOptions;
  int m_selectedPageOrder;
};
}  // namespace select_content
#endif  // ifndef SCANTAILOR_SELECT_CONTENT_FILTER_H_
