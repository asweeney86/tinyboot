#!/bin/bash

DIR="$( cd -P "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $DIR/common.sh

PAD_FILE=/tmp/pad
FLOPPY_FILE=$FLOPPY
KERNEL=$KERNEL
GRUB_OFFSET=102400
STAGE1=$DIR/../grub/grub-0.97-i386-pc/boot/grub/stage1
STAGE2=$DIR/../grub/grub-0.97-i386-pc/boot/grub/stage2

STAGE1_SZ=`du -b $STAGE1 | awk '{ print $1 }'`
STAGE2_SZ=`du -b $STAGE2 | awk '{ print $1 }'`


PAD_SZ=$(($GRUB_OFFSET-$STAGE1_SZ-$STAGE2_SZ))
echo "Stage1 size: $STAGE1_SZ"
echo "Stage2 size: $STAGE2_SZ"
echo "Padding size: $PAD_SZ"

echo "Creating pad file"
dd if=/dev/zero of=$PAD_FILE bs=1 count=$PAD_SZ


echo "Making image"
cat $STAGE1 $STAGE2 $PAD_FILE $KERNEL > $FLOPPY_FILE
