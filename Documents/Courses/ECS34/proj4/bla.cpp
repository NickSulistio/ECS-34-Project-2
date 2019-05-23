#include "CSVWriter.h"
#include "StringUtils.h"



//bool CCSVWriter::WriteRow(const std::vector< std::string > &row){
        //std::vector< std::string > OutputRow;
        //for(auto &Field : row){
            //OutputRow.push_back(std::string("\"") + (StringUtils::Replace(Field, "\"","\"\"") + "\"");"

        }
        Output<<StringUtils::Join(",",OutputRow)<<std::endl;
        return true;
}



