### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> up;

        for(int i = 0; i< nums.size(); i++) {
            up[nums[i]]++;
        }

        for(auto n: up) {
            if(n.second == 1) {
                return n.first;
            }
        }
        return 0;  
    }
};
```