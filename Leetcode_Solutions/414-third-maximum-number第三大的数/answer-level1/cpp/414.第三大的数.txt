### 解题思路
依次找出第一大和第二大的数，判断是否有第三大的数

### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        int n=nums.size();
        int flag=0,i=0;
        for(i=0;i<n;i++)
        {
            max1=max(max1,nums[i]);
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]!=max1)
            max2=max(max2,nums[i]);
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]!=max1 && nums[i]!=max2)
            {
                if(nums[i]>=max3)
                {
                    max3=nums[i];
                    flag++;
                }
            }
        }
        return (flag==0)?max1:max3;
    }
};
```