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

#include "Trigger.h"

using namespace documentdb;
using namespace std;
using namespace utility;

Trigger::Trigger(
	const shared_ptr<const DocumentDBConfiguration>& document_db_configuration,
	const string_t& id,
	const string_t& resource_id,
	unsigned long ts,
	const string_t& self,
	const string_t& etag,
	const string_t& body,
	const TriggerOperation& triggerOperation,
	const TriggerType& triggerType)
	: DocumentDBEntity(document_db_configuration, id, resource_id, ts, self, etag)
	, body_(body)
	, triggerOperation_(triggerOperation)
	, triggerType_(triggerType)
{
	//TODO : deal with body, triggerType, triggerOperation...
}

Trigger::~Trigger()
{
}
