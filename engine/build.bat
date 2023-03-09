@ECHO OFF
SetLocal EnableDelayedExpansion

SET cFilenames =
FOR /R %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

SET assembly=engine
SET compilerFlags=-g -shared -Wvarargs -Wall
SET includeFlags=-Isrc -I%VULKAN_SDK%/Include
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
SET defines=-D_DEBUG -DTEXPORT -D_CRT_NO_SECURE_WARNINGS

ECHO "Building %assembly%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%