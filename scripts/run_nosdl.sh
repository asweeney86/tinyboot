#!/bin/sh

DIR="$( cd -P "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $DIR/common.sh

echo "Starting Composite Use ctrl-a h for help"

$QEMU_EXE \
    -kernel $KERNEL \
    -nographic \
    -m 256 \
    -append "hooray cmdline"


