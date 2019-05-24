CXX=g++

LIBDIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TESTBIN_DIR = ./testbin
CUR_DIR = $(shell pwd)
LIBCSVDIR = libcsv-3.0.3
LIBCSV_NAME = libcsv.a


INCLUDE = -I $(INC_DIR) -I /opt/local/include
CXXFLAGS = -std=c++14 $(INCLUDE)
TESTLDFLAGS += -L '/opt/local/lib'

CFLAGS          +=  -Wall
LDFLAGS         += 
TESTLDFLAGS     += -lgtest -lgtest_main  -lpthread
CPPFLAGS        += -std=c++14 
TESTSTR_NAME    = teststr

STRING_UTILS_OBJ  = $(OBJ_DIR)/StringUtils.o

CSV_READER_OBJ  = $(OBJ_DIR)/CSVReader.o
CSV_WRITER_OBJ  = $(OBJ_DIR)/CSVWriter.o
CSV_TEST_OBJ	= $(OBJ_DIR)/testcsv.o

CSV_TEST_NAME = testcsv 

all: $(LIBDIR)/$(LIB_CSVNAME) directories runtests

runtests: $(TESTBIN_DIR)/$(CSV_TEST_NAME)
	$(TESTBIN_DIR)/$(CSV_TEST_NAME)
	
$(STRING_UTILS_OBJ): $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
	$(CXX) $(SRC_DIR)/StringUtils.cpp -c $(CXXFLAGS) -o $(STRING_UTILS_OBJ)

$(CSV_READER_OBJ): $(SRC_DIR)/CSVReader.cpp $(INC_DIR)/CSVReader.h
	$(CXX) $(SRC_DIR)/CSVReader.cpp -c $(CXXFLAGS) -o $(CSV_READER_OBJ)

$(CSV_WRITER_OBJ): $(SRC_DIR)/CSVWriter.cpp $(INC_DIR)/CSVWriter.h
	$(CXX) $(SRC_DIR)/CSVWriter.cpp -c $(CXXFLAGS) -o $(CSV_WCSVWriter_OBJ)

$(CSV_TEST_OBJ): $(SRC_DIR)/CSVTest.cpp $(INC_DIR)/CSVTest.h
	$(CXX) $(SRC_DIR)/CSVTest.cpp -c $(CXXFLAGS) -o $(CSV_TEST_OBJ)

$(TESTBIN_DIR)/$(CSV_TEST_NAME): $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(CSV_TEST_OBJ) $(STRING_UTILS_OBJ $(LIBDIR)/$(LIBCSV_NAME)
	$(CXX) $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(CSV_TEST_OBJ) $(STRING_UTILS_OBJ) $(LIBDIR)/$(LIB_CSVNAME) $(CXXFLAGS) $(TESTLDFLAGS) -o $(TESTBIN_DIR)/$(CSV_TEST_NAME)

$(LIBCSVDIR)/Makefile:
	cd $(LIBCSVDIR); ./configure --prefix=$(CUR_DIR); cd ..
				
$(LIBCSVDIR)/libcsv.la: $(LIBCSVDIR)/Makefile				
	cd $(LIBCSVDIR); make; cd ..

$(LIBDIR)/$(LIB_CSVNAME): $(LIBCSVDIR)/libcsv.la
	cd $(LIBCSVDIR); make install; cd ..

directories:  $(BIN_DIR) $(TESTBIN_DIR) $(OBJ_DIR) 
	
$(BIN_DIR):
	mkdir $(BINDIR)
$(TESTBIN_DIR):
	mkdir $(TESTBIN_DIR)
$(SRC_DIR):
	mkdir $(SRC_DIR)
$(INC_DIR):
	MKDIR $(INC_DIR)

clean:
	rm -f lib/*
	rm -f include/csv.h
	cd $(LIBCSVDIR); make clean; cd
	rm -f $(LIBCSVDIR)/Makefile
