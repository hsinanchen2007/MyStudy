### 解题思路
在求以i为结尾的最大数，那么只要知道i-1结尾的最大数，加上nums[i]即可
注意题目要求至少选一个，所以在数组全为负数下答案不为0，而是其中最大的负数
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int num=0;   //保存到以i-1为结尾的累积最大的数
       int res=0;   //保存出现过最大的答案
       int k=0;     //用来检测特殊情况（全为负数）的情况
       int m=INT_MIN;    //保存特殊情况下最大的数
       for(int i=0;i<nums.size();i++)
       {
           num=max(0,num+nums[i]);   //当累积数小于0，那么就让num=0
           res=max(num,res);      //保存最大结果
           if(nums[i]<0)   //特殊情况
           {
               k++;
               m=max(m,nums[i]);
           }
       } 
       if(k==nums.size())return m;
       return res;
    }
};
```