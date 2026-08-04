@echo off

IF [%1] == [] (
  echo Expecting a file name to compile
  exit /b 1
)

SET ASM=
REM SET ASM=/FAs
SET CFLAGS=/nologo /W4 /wd4996 /O2 /GS- %ASM%
SET SUBS=console
SET SUBS=windows
SET LFLAGS=/fixed /incremental:no /opt:icf /opt:ref /subsystem:%SUBS% /entry:main
SET LIBS=libvcruntime.lib

cl %CFLAGS% %1 %LIBS% /link %LFLAGS%
del *.obj
