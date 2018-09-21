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

#ifndef _DOCUMENTDB_DOCUMENT_H_
#define _DOCUMENTDB_DOCUMENT_H_

#include <string>
#include <memory>
#include <pplx/pplxtasks.h>

#include "DocumentDBEntity.h"
#include "DocumentDBConfiguration.h"
#include "Attachment.h"
#include "AttachmentIterator.h"

namespace documentdb {
	class Document : public DocumentDBEntity, public std::enable_shared_from_this < Document >
	{
		friend class AttachmentIterator;

	public:
		Document(
			const std::shared_ptr<const DocumentDBConfiguration>& document_db_configuration,
			const utility::string_t& id,
			const utility::string_t& resource_id,
			const unsigned long ts,
			const utility::string_t& self,
			const utility::string_t& etag,
			const utility::string_t& attachments,
			const web::json::value& payload);

		virtual ~Document();

		pplx::task<std::shared_ptr<Attachment>> CreateAttachmentAsync(
			const utility::string_t& id,
			const utility::string_t& contentType,
			const utility::string_t& media) const;

		pplx::task<std::shared_ptr<Attachment>> CreateAttachmentAsync(
			const utility::string_t& id,
			const utility::string_t& contentType,
			const std::vector<unsigned char>& raw_media) const;

		std::shared_ptr<Attachment> CreateAttachment(
			const utility::string_t& id,
			const utility::string_t& contentType,
			const utility::string_t& media) const;

		std::shared_ptr<Attachment> CreateAttachment(
			const utility::string_t& id,
			const utility::string_t& contentType,
			const std::vector<unsigned char>& raw_media) const;

		pplx::task<std::shared_ptr<Attachment>> GetAttachmentAsync(
			const utility::string_t& resource_id) const;

		std::shared_ptr<Attachment> GetAttachment(
			const utility::string_t& resource_id) const;

		pplx::task<std::vector<std::shared_ptr<Attachment>>> ListAttachmentsAsync() const;

		std::vector<std::shared_ptr<Attachment>> ListAttachments() const;

		pplx::task<std::shared_ptr<Attachment>> ReplaceAttachmentAsync(
			const utility::string_t& id,
			const utility::string_t& new_id,
			const utility::string_t& contentType,
			const utility::string_t& media) const;

		std::shared_ptr<Attachment> ReplaceAttachment(
			const utility::string_t& id,
			const utility::string_t& new_id,
			const utility::string_t& contentType,
			const utility::string_t& media) const;

		pplx::task<void> DeleteAttachmentAsync(
			const std::shared_ptr<Attachment>& attachment) const;

		void DeleteAttachment(
			const std::shared_ptr<Attachment>& attachment) const;

		pplx::task<void> DeleteAttachmentAsync(
			const utility::string_t& resource_id) const;

		void DeleteAttachment(
			const utility::string_t& resource_id) const;

		pplx::task<std::shared_ptr<AttachmentIterator>> QueryAttachmentsAsync(
			const utility::string_t& query,
			const int page_size = 10) const;

		std::shared_ptr<AttachmentIterator> QueryAttachments(
			const utility::string_t& query,
			const int page_size = 10) const;

		utility::string_t attachments() const
		{
			return attachments_;
		}

		web::json::value payload() const
		{
			return payload_;
		}
	private:
		std::shared_ptr<Attachment> AttachmentFromJson(
			const web::json::value& json_attachment) const;

		utility::string_t attachments_;
		web::json::value payload_;
	};
}

#endif // ! _DOCUMENTDB_DOCUMENT_H_
