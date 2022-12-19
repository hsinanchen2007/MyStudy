### 解题思路
空间换时间

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> rep(100000);
        int res=-1;
        for(int i=0;i<nums.size();++i)
        {
            rep[nums[i]]++;
            if(rep[nums[i]]>1) 
            {
                res=nums[i];
            }
        }

        return res;
    }
};
```