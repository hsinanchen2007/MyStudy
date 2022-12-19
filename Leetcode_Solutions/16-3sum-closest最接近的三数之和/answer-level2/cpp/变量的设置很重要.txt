### 解题思路

这题求的结果是最接近target的三数之和，因此ans初值可以为该数组的前三个数，接下来的套路和三数之和差不多，排序+双指针，先判断sum==target,成功直接跳出，否则做绝对值大小的判断，小于则刷新ans值。

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
        {
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(target==sum)
                    return sum;
                if(abs(target-sum)<abs(target-ans))
                    ans=sum;
                else if(nums[i]+nums[l]+nums[r]<target)
                    ++l;
                else  
                    --r;
            }
        }
        return ans;
    }
};
```