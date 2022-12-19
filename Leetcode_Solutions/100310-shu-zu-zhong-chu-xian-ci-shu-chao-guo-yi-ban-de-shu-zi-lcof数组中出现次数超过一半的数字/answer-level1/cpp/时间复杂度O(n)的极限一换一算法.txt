# 解题思路
极限一换一
# 时间复杂度和空间复杂度
时间复杂度：O(n)
空间复杂度：O(1)
# 执行结果
执行用时 :
36 ms, 在所有 C++ 提交中击败了30.22%的用户
内存消耗 :18.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        int ans=nums[0];
        int times=1;
        for(int i=1;i<len;i++)
        {
            if(times==0)
            {
                ans=nums[i];
                times=1;
            }
            else if(nums[i]==ans)
            {
                times++;
            }
            else
                times--;
        }
        return ans;
    }
};
```