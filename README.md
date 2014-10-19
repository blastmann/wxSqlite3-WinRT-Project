wxSqlite3 for WinRT
===================

This is a wxSqlite3 WinRT version. It can be used with the great SQLite-Net.

In SQLite-Net, it uses P/Invoke to import the SQLite functions. Maybe I will add a WinRT component version in the future.

## HOW TO?

### Install

There are precompiled packages in 'cmdbuild/build' and 'cmdbuild/build-wp' folder. You can install and use like the original Sqlite package.

I recommend you to use the VSIX packages, rather than reference the solution directly.

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

### Build and pack into VSIX

Open the `cmdbuild` folder, I just pack all you need in this folder. In `tool`, you can run `build-all-msvc.bat` under `VS2013 x86 Native Tools Command Prompt`. Like this:

``` batch
# If you want to build WinRT 8.1 ver, you should set "PLATFORMS=x86 x86_amd64 x86_arm"
# If you want to build WP8.1 ver, set "PLATFORMS=x86 x86_arm"
SET PLATFORMS=x86 x86_amd64 x86_arm
build-all-msvc.bat build
```

You may need to install ActiveTcl 8.5 because there are some tcl script files to run.

If you want 128-bit AES encryption, you can set `CODEC_TYPE=CODEC_TYPE_AES128` in `Makefile.msc`.

For WP81, you need to set `USE_WP81_OPTS=1` in `Makefile.msc`.

When finished compiled, you may want to pack it into VSIX.

``` batch
# for WinRT81
tclsh85 mkvsix.tcl ..\build .. WinRT81 "x86,x64,ARM" 2013

# for WP81
tclsh85 mkvsix.tcl ..\build .. WP81 "x86,ARM" 2013
```

After that, you just get two VSIX plugins. Install and enjoy.

## License

The same as wxSqlite3.

