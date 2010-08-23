/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Query.h"

namespace Lucene
{
	/// Base class for span-based queries.
	class LPPAPI SpanQuery : public Query
	{
	public:
		virtual ~SpanQuery();
		LUCENE_CLASS(SpanQuery);
	
	public:
		/// Returns the matches for this query in an index.  Used internally to search for spans.
		virtual SpansPtr getSpans(IndexReaderPtr reader) = 0;
		
		/// Returns the name of the field matched by this query.
		virtual String getField() = 0;
		
		virtual WeightPtr createWeight(SearcherPtr searcher);
	};
}