/*
 * Copyright 2009 Jakub Wieczorek <faw217@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifndef OPENSEARCHREADER_H
#define OPENSEARCHREADER_H

#include <qxmlstream.h>

#include "opensearchengine.h"

class OpenSearchReader : public QXmlStreamReader
{
public:
    OpenSearchReader();
    OpenSearchEngine *read(QIODevice *device);

private:
    void readDocument();
    void readName();
    void readDescription();
    void readUrl();
    void readParameter(OpenSearchEngine::Parameters *parameters);
    void readImage();
    void readTags();
    void skipSubtree();

private:
    OpenSearchEngine *m_engine;
};

#endif // OPENSEARCHREADER_H
