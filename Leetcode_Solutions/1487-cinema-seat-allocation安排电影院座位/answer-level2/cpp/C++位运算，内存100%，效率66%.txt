一开始用数组存，被n=10^9用例卡住了，迫不得已看题解用位运算，真好用。
```
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> bitMap;
        for (auto &r : reservedSeats) {
            bitMap[r[0]] |= (1 << (r[1] - 1));
        }

        int answer = (n - bitMap.size()) * 2; // 全部空闲的行，必定有2个符合4人家庭

        int match1 = 0b0111111110;
        int match2 = 0b0111100000;
        int match3 = 0b0001111000;
        int match4 = 0b0000011110;

        for (auto &m : bitMap) {
            if ((m.second & match1) == 0) {
                answer += 2;
            }
            else if ((m.second & match2) == 0 || (m.second & match3) == 0 || 
                (m.second & match4) == 0) {
                answer += 1;
            }
        }

        return answer;
    }
};
```
