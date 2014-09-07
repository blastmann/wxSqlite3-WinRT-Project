#ifndef SQLITE_CODECEXT_H
#define SQLITE_CODECEXT_H

#include "sqlite3.h"

int sqlite3_key(sqlite3 *db, const void *zKey, int nKey);

int sqlite3_key_v2(sqlite3 *db, const char *zDbName, const void *zKey, int nKey);

int sqlite3_rekey_v2(sqlite3 *db, const char *zDbName, const void *zKey, int nKey);

int sqlite3_rekey(sqlite3 *db, const void *zKey, int nKey);

#endif SQLITE_CODECEXT_H
