wxSqlite3 for WinRT
===================

This is a wxSqlite3 WinRT version. It can be used with the great SQLite-Net.

In SQLite-Net, it uses P/Invoke to import the SQLite functions. Maybe I will add a WinRT component version in the future.

## HOW TO?

### Encrypt/Decrypt?

Right now, you can use the SQLite-Net source files in this project. It's already have a encrypt/decrypt porting. You can just call the `SetDbkey(string key)` to encrypt your database. After that, you can call `Key(string key)` to decrypt after you open your database.

Here is an example:

``` c#
var conn = new SQLiteAsyncConnection("db.sqlite");

// Set a key to your databse first
// Then you can copy your db file from your device
await conn.SetDbKeyAsync("Hello World!");

// Input your key to database
await conn.KeyAsync("Hello World!");

// Your CURD codes...
...


conn.dispose;

```

### Use this library

Just build the solution and copy those dll files to your own solution. I wanna make this more easy later
