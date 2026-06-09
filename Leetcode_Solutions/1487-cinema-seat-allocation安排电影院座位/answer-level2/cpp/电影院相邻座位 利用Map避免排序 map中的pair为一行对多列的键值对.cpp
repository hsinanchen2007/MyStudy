### 解题思路
利用Map避免排序 
map中的pair为一行对多列的键值对：
<1,{2,3,8}>
<2,{6}>
<3,{1,10}>

对于没有预定的行，每行按照2个家庭座位算:2 * (n - mymap.size());
对于有预定的行，要逐个计算没有被预定的家庭座位 :count

要记录标记位，避免重复计算

### 代码

```cpp
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int size = reservedSeats.size();
        unordered_map<int, unordered_set<int>>mymap;
        int count = 0;
    
        for (auto seat : reservedSeats) {
            mymap[seat[0]].insert(seat[1]);
        }
        CheckNext(mymap, count);
        return count + 2 * (n - mymap.size());
    } 
private:
    void CheckNext(unordered_map<int, unordered_set<int>>& mymap,int& count)
    {
            for (auto m : mymap) {
                int marked = 0;
                if (m.second.count(2) == 0 && m.second.count(3) == 0 && m.second.count(4) == 0 && m.second.count(5) == 0) {
                    count ++;
                    marked = 1;
                } 
                if (m.second.count(6) == 0 && m.second.count(7) == 0 && m.second.count(8) == 0 && m.second.count(9) == 0) {
                    count ++;
                    marked = 1;
                } 
                if (marked == 0 && m.second.count(4) == 0 && m.second.count(5) == 0 && m.second.count(6) == 0 && m.second.count(7) == 0) {
                    count ++;  // 通过marked标记，避免2345 和6789都可用时，4567又被重复计数
                }
            }
            return ;
    }
};

// int main()
// {
//     int rows = 3;
//     vector<vector<int>> reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
//     Solution s;
//     int result = s.maxNumberOfFamilies(rows, reservedSeats);
//     cout << "The result is " << result << endl;
//     system("pause");
//     return 0;
// }


附上一道类似题目：统计高铁相邻座位个数
// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int NumSeats(int rows, vector<string> &seats)
//     {
//         unordered_map<string, unordered_set<char>>mymap;
//         int count = 0;
//         for (auto seat : seats) {
//             mymap[seat.substr(0,seat.size()-1)].insert(seat[seat.size()-1]);
//         }
//         CheckNext(mymap, count); 
//         return 2*rows - count;  // 总的相邻座位个数减去被消耗掉的
//     }

// private:
//     void CheckNext(unordered_map<string, unordered_set<char>> &mymap, int& count)
//     {
//         for (auto m : mymap) {
//             if (m.second.count('B')==1 || (m.second.count('A')==1 && m.second.count('C')==1) ) { // B被占用或者 A和C同时被占用时才消耗一个相邻座位
//                 count++;
//             }
//             if (m.second.count('D')==1 || (m.second.count('F')==1)) { // D和F只要一个被占用就消耗一个相邻座位
//                 count++;
//             }
//         }
//         return;
//     }
// };

// int main()
// {
//     int rows = 4;
//     //vector<string> seats = {"3A", "4A", "33A", "44A", "44B", "3B", "3C"};
//     vector<string> seats = {"3A", "3B", "4F"};
//     Solution s;
//     int result = s.NumSeats(rows, seats);
//     cout << "The result is " << result << endl;
//     system("pause");
//     return 0;
// }