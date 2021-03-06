// Copyright (C) 2019  Joseph Artsimovich <joseph.artsimovich@gmail.com>, 4lex4 <4lex49@zoho.com>
// Use of this source code is governed by the GNU GPLv3 license that can be found in the LICENSE file.

#ifndef SCANTAILOR_CORE_PAGESELECTIONPROVIDER_H_
#define SCANTAILOR_CORE_PAGESELECTIONPROVIDER_H_

#include <set>
#include <vector>

#include "ref_countable.h"

class PageSequence;
class PageId;
class PageRange;

class PageSelectionProvider : public ref_countable {
 public:
  virtual PageSequence allPages() const = 0;

  virtual std::set<PageId> selectedPages() const = 0;

  virtual std::vector<PageRange> selectedRanges() const = 0;
};


#endif
