#!/bin/bash

premake5 gmake
cd build
make config=debug
../bin/Debug/GraphC