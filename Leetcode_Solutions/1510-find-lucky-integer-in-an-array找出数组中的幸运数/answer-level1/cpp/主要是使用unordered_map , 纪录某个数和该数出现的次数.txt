### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> numCnt;  // num & num cnt
        int maxLucky = -1;
        for (auto &ele : arr) {
            numCnt[ele]++;
        }
        for (auto &eleNum : arr) {
            if (eleNum == numCnt[eleNum]) {
                maxLucky = max(maxLucky, eleNum);
            }
        }
        return maxLucky;
    }
};
```