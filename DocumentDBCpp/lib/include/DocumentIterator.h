/***
* The MIT License (MIT)
*
* Copyright (c) 2015 DocumentDBCpp
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
***/

#ifndef _DOCUMENTDB_DOCUMENT_ITERATOR_H_
#define _DOCUMENTDB_DOCUMENT_ITERATOR_H_

#include <memory>

#include <cpprest/json.h>

#include "DocumentDBConfiguration.h"
#include "Document.h"

namespace documentdb
{
	class Collection; // forward declaration

	class DocumentIterator
	{
	public:
		DocumentIterator(
			const std::shared_ptr<const Collection>& collection,
			const utility::string_t& original_query,
			const int page_size,
			const utility::string_t& original_request_uri,
			const utility::string_t& continuation_id,
			const web::json::value& buffer);
		virtual ~DocumentIterator();

		bool HasMore();

		std::shared_ptr<Document> Next();

	private:
		std::shared_ptr<const Collection> collection_;
		utility::string_t original_query_;
		int page_size_;
		utility::string_t original_request_uri_;
		utility::string_t continuation_id_;
		web::json::value buffer_;
		unsigned int current_;
	};
}

#endif // !_DOCUMENTDB_DOCUMENT_ITERATOR_H_
