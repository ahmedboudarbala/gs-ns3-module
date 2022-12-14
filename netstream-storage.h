/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************
 **                                                                    **
 ** \author Axel Wegener <wegener@itm.uni-luebeck.de>                  **
 ** \author Bjoern Hendriks <hendriks@ibr.cs.tu-bs.de>                 **
 **                                                                    **
 ************************************************************************/
#ifndef __NETSTREAM_STORAGE_H
#define __NETSTREAM_STORAGE_H


#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>

namespace ns3
{

class NetStreamStorage
{
  friend std::ostream& operator<<(std::ostream &, const NetStreamStorage &);
  

public:
	typedef std::vector<unsigned char> StorageType;

private:
	StorageType store;
	StorageType::const_iterator iter_;

	// sortation of bytes forwards or backwards?
	bool bigEndian_;

	/// Used in constructors to initialize local variables
	void init();

	/// Check if the next \p num bytes can be read safely
	void checkReadSafe(unsigned int num) const throw();
	/// Read a byte \em without validity check
	unsigned char readCharUnsafe();
	/// Write \p size elements of array \p begin according to endianess
	void writeByEndianess(const unsigned char * begin, unsigned int size);
	/// Read \p size elements into \p array according to endianess
	void readByEndianess(unsigned char * array, int size);


  
public:

	/// Standard Constructor
	NetStreamStorage();

	/// Constructor, that fills the storage with an char array. If length is -1, the whole array is handed over
	NetStreamStorage(unsigned char[], int length=-1);

	// Destructor
	virtual ~NetStreamStorage();

	virtual bool valid_pos();
	virtual unsigned int position() const;

	void reset();

	virtual size_t varintSize(uint_fast64_t);
	virtual uint_fast64_t readUnsignedVarint() throw();
	virtual void writeUnsignedVarint(uint_fast64_t) throw();

	virtual int_fast64_t readVarint() throw();
	virtual void writeVarint(int_fast64_t) throw();

	virtual unsigned char readChar() throw();
	virtual void writeChar(unsigned char) throw();

	virtual int readByte() throw();
	virtual void writeByte(int) throw();
//	virtual void writeByte(unsigned char) throw();

	virtual int readUnsignedByte() throw();
	virtual void writeUnsignedByte(int) throw();

	virtual std::string readString() throw();
	virtual void writeString(const std::string& s) throw();

	virtual std::vector<std::string> readStringList() throw();
	virtual void writeStringList(const std::vector<std::string> &s) throw();

	virtual int readShort() throw();
	virtual void writeShort(int) throw();

	virtual int readInt() throw();
	virtual void writeInt(int) throw();

	virtual long readLong() throw();
	virtual void writeLong(long) throw();

	virtual float readFloat() throw();
	virtual void writeFloat( float ) throw();

	virtual double readDouble() throw();
	virtual void writeDouble( double ) throw();

	virtual void writePacket(unsigned char* packet, int length);

	virtual void writeStorage(NetStreamStorage& store);

  virtual NetStreamStorage operator+(const NetStreamStorage & storage);

  
	// Some enabled functions of the underlying std::list
	StorageType::size_type size() const { return store.size(); }

	StorageType::const_iterator begin() const { return store.begin(); }
	StorageType::const_iterator end() const { return store.end(); }

};

} // namespace tcpip

#endif // NETSTREAM_STORAGE


/*-----------------------------------------------------------------------
 * Source  $Source: $
 * Version $Revision: 426 $
 * Date    $Date: 2010-05-31 12:05:13 +0200 (Mon, 31 May 2010) $
 *-----------------------------------------------------------------------
 * $Log: $
 *-----------------------------------------------------------------------*/
