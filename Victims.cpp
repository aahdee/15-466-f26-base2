#include "Victims.hpp"

#include "gl_errors.hpp"
#include "read_write_chunk.hpp"
#include <fstream>

void Victims::load(std::string const &filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "cannot open victims file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        Victim v;
        std::string sDelimiter = ";";
        std::string eDelimiter = ">";

        size_t split = line.find(sDelimiter);
        size_t end = line.find(eDelimiter);
        v.description = line.substr(0, split);
        v.value = std::stoi(line.substr(split+1,end-1));
        victims_list.emplace_back(v);
    }

}

Victims::Victims(std::string const &filename){
    load(filename);
}