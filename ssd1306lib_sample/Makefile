#    MIT License
#
#    Copyright (c) 2018, Alexey Dynda
#
#    Permission is hereby granted, free of charge, to any person obtaining a copy
#    of this software and associated documentation files (the "Software"), to deal
#    in the Software without restriction, including without limitation the rights
#    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#    copies of the Software, and to permit persons to whom the Software is
#    furnished to do so, subject to the following conditions:
#
#    The above copyright notice and this permission notice shall be included in all
#    copies or substantial portions of the Software.
#
#    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#    SOFTWARE.
#
#################################################################


INC=./inc
LIB_FOLDER ?= ./ssd1306_lib_arm
CCFLAGS += -MD -g -Os -w -ffreestanding $(INCLUDES) -Wall -Werror \
	-Wl,--gc-sections -ffunction-sections -fdata-sections \
	$(EXTRA_CCFLAGS)

INCLUDES += -I./$(INC)
OUTFILE=ssd1306.out

SRCS += main.cpp
OBJS = main.o
LDFLAGS += -L$(LIB_FOLDER) -lssd1306

all: ssd1306

ssd1306: $(OBJS)
	$(CC) -o $(OUTFILE) $(CCFLAGS) $(OBJS) $(LDFLAGS)

$(OBJS): main.cpp
	$(CXX) -std=c++11 $(CCFLAGS) $(CXXFLAGS) $(CCFLAGS-$(basename $(notdir $@))) -c $< -o $@

clean:
	rm -f *~ *.out *.bin *.hex *.srec *.s *.o *.d *.pdf *core
