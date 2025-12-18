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


vector<string> split(const string& line) {
    vector<string> result;
    string field;
    bool inQuotes = false;

    for (size_t i = 0; i < line.length(); i++) {
        char c = line[i];

        if (c == '"') 
            inQuotes = !inQuotes;
        else if (c == ',' && !inQuotes) 
        {
            result.push_back(field);
            field.clear();
        }
        else 
            field += c;
    }
    result.push_back(field);
    return result;
}

int main() {
    // هدر CSV: همه رشته‌ها داخل کوتیشن
    vector<string> headers = {
        "model", "mpg", "cyl", "disp", "hp",
        "drat", "wt", "qsec", "vs", "am",
        "gear", "carb"
    };

    // چاپ هدرها
    cout << "CSV Headers:" << endl;
    for (auto& h : headers)
        cout << " [ " << h << " ] ";
    cout << "\n\n";

    // نمونه خط CSV
    string line = "Mazda RX4,21.0,6,160,110,3.9,2.62,16.46,0,1,4,4";
    vector<string> fields = split(line);

    cout << "CSV Fields:" << endl;
    for (auto& f : fields)
        cout << " [ " << f << " ] ";
    cout << endl;

    cin.get();
    return 0;
}