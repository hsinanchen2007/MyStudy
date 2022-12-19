### 解题思路

- 找到状态方程:dp[i]=max(dp[i-1]+num,num)
- 但是最后一行 max=curmax > max ? curmax:max; 代码还是不理解，为什么curmax不是最大值，非要引入max，还得慢慢琢磨
- 上一行的问题理解了:需要比较所有子序列的最大值，才能得到全局最大值，而max正在不断维护全局最大值

### 代码

```cpp
class Solution {
public:
     
    int maxSubArray(vector<int>& nums) {
        int curmax=0;//记录当前序列的最大值
        int max=nums[0];//全局最大值
        for(int i=1;i<nums.size();i++)
        {   //套公式
           if(curmax<0)
           {
               curmax=nums[i];
           }
           else{
               curmax=nums[i]+curmax;
           }
        max=curmax > max ? curmax:max;//也可以直接用max函数
        }
        return max;
        
    }
};
```