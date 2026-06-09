执行用时 :4 ms, 在所有 C++ 提交中击败了79.38% 的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了84.69%的用户

思路直接上代码，比较好理解。

```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];//长度为1时，返回这个数
        if(nums.size()==2)
            return max(nums[0],nums[1]);//长度为2时，返回大的数
        int max_[nums.size()+1];//设f(n)为求解的答案
        max_[0]=0;//f(0)
        max_[1]=nums[0];//f(1)
        max_[2]=max(nums[0],nums[1]);//f(2)
        for (int i=3;i<=nums.size();i++){//这里i是数组的长度，对应数组下标为i-1
            max_[i]=max((max_[i-1]),(nums[i-1]+max_[i-2]));//f(3)=max{f(2)+f(1)+nums[2]}
            //以此类推
        }
        return max_[nums.size()];
    }
};
```
