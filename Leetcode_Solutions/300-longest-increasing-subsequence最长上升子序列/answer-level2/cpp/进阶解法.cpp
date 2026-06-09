**解题思路：**
    -我们逐步生成一个升序的数列，最后数列的长度就是最长子序列的长度。
    -因为序列可以有多重，但最长长度是一定的，因为我们使用贪心思想，每次添加一个元素，使得得到的序列可以尽可能长。
    --具体生成方式见下边的步骤

**解题过程如下：**
# 例子：4 9 2 5 3 7 101 18
    *index=0;
    dp={4};   // 初始直接添加
    index=1;
    dp={4,9};  // 因为9比4大，因此添加到末尾构成升序序列
    index=2;
    dp={2,9};  // 因为2比序列最后一个元素小，因此找到序列中大于2的第一个元素4，用2替换4
               // 因为只有前边的元素尽可能小，生成的生序序列长度才尽可能长
之后逐步遍历dp的变化如下：
    2  5  
    2  3  
    2  3  7  
    2  3  7  101  
    2  3  7  18  
最后得到最长子序列的长度是4.*

代码：
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        
        vector<int> dp;
        dp.push_back(nums[0]);
        if(n==1) return 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>dp[dp.size()-1]) dp.push_back(nums[i]);
            else
            {
                auto it=lower_bound(dp.begin(),dp.end(),nums[i]);
                *it=nums[i];
            }
           
        }
      
        return dp.size();
    }
};
```



