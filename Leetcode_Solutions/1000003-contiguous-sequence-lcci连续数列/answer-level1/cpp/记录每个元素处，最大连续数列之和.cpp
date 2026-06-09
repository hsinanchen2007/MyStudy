
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res;
        int n=nums.size();
        //用于记录截止到每个元素，连续数列的最大总和（至少有一个元素）
        vector<int> maxnums(n,0);

        maxnums[0]=nums[0];
        res=maxnums[0];
        for(int i=1;i<n;i++)
        {
            //截止到每个元素的最大总和连续序列，必须要有该元素
            maxnums[i]=max(maxnums[i-1]+nums[i],nums[i]);
            res=max(res,maxnums[i]);
        }

        return res;
    }
};
```