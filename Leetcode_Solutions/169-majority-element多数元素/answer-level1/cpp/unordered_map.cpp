### 解题思路
unordered_map实现
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> m;
        for(auto num:nums) {
            m[num]++;
            if(m[num]>len/2)
                return num;
        } 
        return -1;
    }
};
```