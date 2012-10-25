#!/bin/bash

if [[ "${BASH_SOURCE[0]}" == "${0}"  ]]; then
    echo "This file must be sourced"
    exit -1
fi

DIR="$( cd -P "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

QEMU_EXE=qemu-system-x86_64
KERNEL=$DIR/../kernel.img
FLOPPY=$DIR/../floppy.img
