// Copyright (C) 2019  Joseph Artsimovich <joseph.artsimovich@gmail.com>, 4lex4 <4lex49@zoho.com>
// Use of this source code is governed by the GNU GPLv3 license that can be found in the LICENSE file.

#ifndef SCANTAILOR_PAGE_LAYOUT_GUIDE_H_
#define SCANTAILOR_PAGE_LAYOUT_GUIDE_H_

#include <QDomElement>
#include <QtCore>

namespace page_layout {
class Guide {
 public:
  Guide();

  Guide(Qt::Orientation orientation, double position);

  Guide(const QLineF& line);

  explicit Guide(const QDomElement& el);

  QDomElement toXml(QDomDocument& doc, const QString& name) const;

  operator QLineF() const;

  Qt::Orientation getOrientation() const;

  double getPosition() const;

  void setPosition(double position);

 private:
  static Qt::Orientation lineOrientation(const QLineF& line);

  static QString orientationToString(Qt::Orientation orientation);

  static Qt::Orientation orientationFromString(const QString& str);

  Qt::Orientation m_orientation;
  double m_position;
};
}  // namespace page_layout

#endif  // ifndef SCANTAILOR_PAGE_LAYOUT_GUIDE_H_