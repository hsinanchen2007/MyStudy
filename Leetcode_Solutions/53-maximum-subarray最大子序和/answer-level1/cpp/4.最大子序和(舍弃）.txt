### 解题思路
主要思想是为负数的当前元素肯定不是最优起点，只要子序列和为负肯定可以舍弃
但是一定要注意这样直接写会忽略全为负数的数组情况
为什么max_element()函数会用不了啊啊啊啊啊啊啊啊啊啊啊啊啊

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max=0,flag=0,i,maxx=nums[0];
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>max) max=sum;
            else if(sum<0) sum=0;
            if(nums[i]>0) flag=1;   
            if(nums[i]>maxx) maxx=nums[i]; //找全为负数数组中最大的数
        }
        if(flag)
        return max;
        else 
        return maxx;
    }
};
```