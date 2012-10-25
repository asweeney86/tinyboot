#!/bin/sh

DIR="$( cd -P "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $DIR/common.sh


$QEMU_EXE \
    -kernel $KERNEL \
    -serial stdio \
    -append "hooray cmdline" \
    -s -S &

gdb
