### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0,even = 0;
        for(auto chip:chips){
            if(chip & 1)++odd;
            else ++even;
        }
        return min(odd,even);
    }
};
```