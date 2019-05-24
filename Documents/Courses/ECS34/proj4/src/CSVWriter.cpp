#include "CSVWriter.h"
#include "StringUtils.h"

CSSVWriter::CCSVWriter(std::ostream &ou) : Output(ou){
	
}

CCSVWriter::~CCSVWriter(){

}

bool CCSVWriter::WriteRow(const std::vector< std::string > &row){
	std::vector< std::string > Temp;
	for(auto &Field : row){
		Temp.push_back(std::string("\"") + StringUtils::Replace(Field,"\"","\"\"")+ "\"");
	}
	Output<<StringUtils::Join(",",Temp)<<std::endl;
	return Output.good();
