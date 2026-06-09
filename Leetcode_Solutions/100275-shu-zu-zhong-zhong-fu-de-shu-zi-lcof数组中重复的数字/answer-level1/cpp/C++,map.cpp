### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len=nums.size();
        vector<int> map(len,0);
        for(auto num:nums){
            map[num]++;
            if(map[num]>1) return num;
        }
        return -1;
    }
};
```