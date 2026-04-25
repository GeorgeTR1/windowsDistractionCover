### Discription
Creates a window with a black background that always stays on top of any other windows. Move and resize it as you would like, and then double click in the window to change it to a plain black rectangle with no borders or shadow. This is intended to cover up portions of the screen that you don't want to see for some reason, presumably because they are distracting. Double click in the window again to change it back to the bordered version to resize or move it again, or to close it. Just download the executable file from releases, there are no dependencies that aren't part of the OS.

### Technical details
The resulting executable file is tiny, just 3 kB. It was compiled on Windows 10 64-bit, and should work for Windows 10 and 11, as well as probably older 64-bit versions of Windows, but I haven't tested this. The source code should work for all versions of Windows going back to Windows 95, if compiled properly. Some very minor tweaks might be necessary; just removing the `#pragma` directives and maybe changing `main` to `WinMain` depending on if the compiler you're using allows you to set an entry point should be all that's necessary. Again, I haven't tested this, but all of the funcitons, sturctures, constants, etc. are supported in Windows 95, unless I somehow missed something. If anyone compiles a version that works in all versions of Windows going back to 95, that would be very cool, I'd appreciate it if you let me know. I imagine the file would probably be slightly bigger, but who knows.

### Building
The source code is just a single C file. Other than the three `#pragma` directives that specify the libraries that the program needs to link with, nothing is compiler specific, so it should compile in any C compiler that targets Windows if you remove those and link with those libraries in a different way. But, to do it just how I did it and get a tiny executable, do the following:
1. Download `cc.bat` and `cover.c` into the same directory
2. Open a command prompt where you can use MSVC. This can be with Visual Studio, Visual Studio build tools, or using the instructions [here](https://gist.github.com/mmozeiko/7f3162ec2988e81e56d5c4e22cde9977). Works with VS2022 and VS2026, not sure about older versions
3. Navigate to the directory where you downloaded the files
4. Run `cc cover.c`

### Credits
- This [gist](https://gist.github.com/mmozeiko/81e9c0253cc724638947a53b826888e9) by [@mmozeiko](https://github.com/mmozeiko) for information on how to make compile tiny Windows binaries using MSVC
- *Programming Windows, 5th Ed.* by Charles Petzold for general information on how to program with the Win32 API
- [Windows 95 API reference](https://archive.org/download/nt40_win95_sdk1996/nt40_win95_sdk1996.iso/DOC%2FHLP%2FWIN32SDK.HLP), available on the Internet Archive as a .HLP file (see [listing](https://archive.org/details/nt40_win95_sdk1996)). For help opening .HLP files on modern systems, see [here](https://eileenslounge.com/viewtopic.php?p=281561#p281561)
