/*
 * Copyright (c) 2010 Remko Tronçon
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#include <boost/filesystem/fstream.hpp>
#include <cassert>

#include "Swiften/FileTransfer/FileWriteBytestream.h"

namespace Swift {

FileWriteBytestream::FileWriteBytestream(const boost::filesystem::path& file) : file(file), stream(NULL) {
}

FileWriteBytestream::~FileWriteBytestream() {
	if (stream) {
		stream->close();
		stream = NULL;
	}
}

void FileWriteBytestream::write(const ByteArray& data) {
	if (!stream) {
		stream = new boost::filesystem::ofstream(file, std::ios_base::out|std::ios_base::binary);
	}
	assert(stream->good());
	stream->write(data.getData(), data.getSize());
}

}