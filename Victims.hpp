#include <string>
// #include <unordered_map>
#include <list>

struct Victims{
    //each victim has a text description and a value
    struct Victim{
        std::string description;
        int value;
    };
    std::list <Victim> victims_list;
    //add victims from the file
    void load(std::string const &filename);
    Victims() = default;

    Victims(std::string const &filename);
    
};