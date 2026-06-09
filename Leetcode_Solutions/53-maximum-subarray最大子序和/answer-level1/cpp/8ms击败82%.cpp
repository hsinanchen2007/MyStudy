### 解题思路
在一个新数组中记录nums[i]元素的最大自序和,如果nums[i]与nums[i-1]的自序和相加小于nums[i]本身,则放弃加上之前的序列,新数组中记录nums[i]的值(相当于最大序列和从当前值重新开始统计序列和)...

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> results;
        int themax=nums[0];
        results.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]+results[i-1]<nums[i])//比较
            {
                results.push_back(nums[i]);//插入当前值
                if(nums[i]>themax)themax=nums[i];//记录最大值
            }
            else
            {
                results.push_back(nums[i]+results[i-1]);//数组中插入序列和
                if(nums[i]+results[i-1]>themax)themax=nums[i]+results[i-1];//记录最大值
            }
            
        }
        return themax;
    }
};
```