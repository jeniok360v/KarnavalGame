@echo off

mkdir ..\build
pushd ..\build
cd
cl /Zi ..\code\win_32.cpp user32.lib
popd

