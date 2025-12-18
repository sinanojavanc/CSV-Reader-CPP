#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class csvrdr {
private:
    ifstream iFile;

public:
    csvrdr(const string& file_name);
    ~csvrdr();

    bool readLine(string& line);
    vector<string> split(const string& line);

};


csvrdr::csvrdr(const string& file_name){
    iFile.open(file_name);
    if (!iFile.is_open()) {
        cerr << "Failed to open file\n";
    }
}

csvrdr::~csvrdr(){
    if (iFile.is_open())
        iFile.close();
}


bool csvrdr::readLine(string& line){
    return static_cast<bool>(getline(iFile, line));
}

vector<string> split(const string& line){
    vector<string> temp;
    string remaining = line;
    size_t  Index;

    while (!remaining.empty())
    {   
        Index = remaining.find(',');
        if (Index == string::npos) 
        {
            temp.push_back(remaining);
            break;
        }
        else 
        {
            temp.push_back(remaining.substr(0, Index));
            remaining = remaining.substr(Index + 1);
        }
    }
    return temp;
}

int main() {
    string line = "Ali,20,Tehran";
    vector<string> result = split(line);

    for (auto& s : result)
        cout << s << endl;

    return 0;
}
