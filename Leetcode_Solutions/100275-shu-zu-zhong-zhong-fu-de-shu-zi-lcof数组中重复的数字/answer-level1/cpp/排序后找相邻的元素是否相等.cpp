### 解题思路
暴力法，执行用时 :
60 ms
, 在所有 C++ 提交中击败了
54.35%
的用户
内存消耗 :
24.9 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len=nums.size();
        if (len==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return nums[i];
            }
        }
        return 0;
    }
};
```