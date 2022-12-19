### 解题思路
暴力法效率较低执行用时 :2208 ms, 在所有 cpp 提交中击败了5.38%的用户
### 代码

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int count;
        int ret=1;
        int first;
        for(int i=0;i<nums.size();i++)
        {
            count=1;
            first=nums[i];
            while(first!=i)
            {
                first=nums[first];
                ++count;
            }
            ret=max(ret,count);
        }
        return ret;
    }
};
```