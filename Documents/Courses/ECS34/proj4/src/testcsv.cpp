#include "CSVREADER.h"
#include "CSVWriter.h"
#include <sstream>
#include <gtest/gtest.h>

TEST(CSVReader, BasicTest){
	std::stringstream In("INSERT THE TEST HERE");
	CCSVReader Reader(In);
	std::vector<std::string> Row;

	EXPECT_TRUE(Reader.ReadRow(Row));
	EXPECT_EQ(Row.size(), 5);
	if(Row.size() >=5){
		EXPECT_EQ(Row[0],"1");
		EXPECT_EQ(Row[0], “2”);
		EXPECT_EQ(Row[0], “3”);
		EXPECT_EQ(Row[0], “4”);
		EXPECT_EQ(Row[0], “5”);
	}
}

TEST(CSVWriter, BasicTest){
	std::stringstream Out;
	CCSVWriter Writer(Out);
	std::vector<std::string> Row{"1","2","3","4","5"};

	EXPECT_TRUE(Writer.WriteRow(Row));
	EXPECT_EQ(Out.str(), "\n", "1\", "2\"
