#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include<string>
#include<vector>

using namespace std;
class elevator {
    private:
        static constexpr int TIME_PER_FLOOR = 10; 
        int current_floor;
        vector<int> floors_visited;
        long long timeTraveled; // using long long for exceptionally long elevator rides
    public:
        elevator(int x, const vector<int>& y)
        {
            current_floor = x; 
            floors_visited = y; //sets floors_visited to an array only containing the start floor
            timeTraveled = 0;
        }

        void move_to_floor(int floor) // calculates time spent and appends floor to visited floor
        {
            
            if (floor == current_floor) return;
            timeTraveled += abs(static_cast<long long>(current_floor) - floor) * TIME_PER_FLOOR;
            current_floor = floor; 
            floors_visited.push_back(floor); 
        }

        const vector<int>& getFloors() const
        {
            return floors_visited;
        }

        long long getTimeTraveled() const
        {
            return timeTraveled;
        }
};

    int parseStart(string startStr) // helper function to parse start string into an integer
    {
        string prefix = "start=";
        if(startStr.compare(0, prefix.size(), prefix) != 0) // arg check
        {
            throw invalid_argument("Usage: ./elevator start=<floor> floor=<f1,f2,...");
        }
        string number = startStr.substr(prefix.size());

        return stoi(number);

    }

    vector<int> parseFloors(string floorStr) // helper function to parse floors into a vector
    {
        string prefix = "floor=";
       
        if(floorStr.compare(0, prefix.size(), prefix) != 0) // arg check
        {
            throw invalid_argument("Usage: ./elevator start=<floor> floor=<f1,f2,...");
        } 
        string number = floorStr.substr(prefix.size());
        stringstream ss(number);
        string token;
        vector<int> floors;
        while(std::getline(ss, token, ','))
        {
            floors.push_back(stoi(token));
        }
        return floors;
    }



int main(int argc, char* argv[]) {
if (argc != 3) 
{
    cerr << "Usage: ./elevator start=<floor> floor=<f1,f2,...>\n";
    return 1;
}
int start;
vector<int> floors;
try //catches any other invalid arguments.
    {
        start = parseStart(argv[1]);
        floors = parseFloors(argv[2]);
    } 
catch (const exception& e)
    {
    cerr << "Error: " << e.what() << "\n";
    return 1;
    }

elevator MyElevator(start, {start}); // initialize elevator with starting floor and a vector with starting floor appended.

for(int i = 0; i < floors.size(); i ++) //loops through floors and moves the elevator
    {
        MyElevator.move_to_floor(floors[i]);
    }

cout<< MyElevator.getTimeTraveled() << " ";
const auto& visited = MyElevator.getFloors();
for (size_t i = 0; i < visited.size(); i++) 
    {
    if (i > 0) cout << ",";
    cout << visited[i];
    }
cout << "\n";
return 0;
}


