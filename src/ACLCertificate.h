
/*
 * $Id: ACLCertificate.h,v 1.3 2003/02/25 12:22:33 robertc Exp $
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 *
 * Copyright (c) 2003, Robert Collins <robertc@squid-cache.org>
 */

#ifndef SQUID_ACLCERTIFICATE_H
#define SQUID_ACLCERTIFICATE_H
#include "ACL.h"
#include "ACLData.h"
#include "ACLChecklist.h"
#include "ssl_support.h"
#include "ACLStrategised.h"

class ACLCertificateStrategy : public ACLStrategy<SSL *>
{

public:
    virtual int match (ACLData<MatchType> * &, ACLChecklist *);
    static ACLCertificateStrategy *Instance();
    /* Not implemented to prevent copies of the instance. */
    /* Not private to prevent brain dead g+++ warnings about
     * private constructors with no friends */
    ACLCertificateStrategy(ACLCertificateStrategy const &);

private:
    static ACLCertificateStrategy Instance_;
    ACLCertificateStrategy(){}

    ACLCertificateStrategy&operator=(ACLCertificateStrategy const &);
};

class ACLCertificate
{

private:
    static ACL::Prototype UserRegistryProtoype;
    static ACLStrategised<SSL*> UserRegistryEntry_;
    static ACL::Prototype CARegistryProtoype;
    static ACLStrategised<SSL *> CARegistryEntry_;
};

#endif /* SQUID_ACLCERTIFICATE_H */