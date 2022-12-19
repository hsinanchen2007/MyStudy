### 解题思路

### 代码

```cpp
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n=nums.size(),ac=0;
        for(int i=n/2-1;i>=0;i--) update(i,n,nums);

        while(ac!=k)
        {
            swap(nums[0],nums[n-1]);
            update(0,n-1,nums);
            n--,ac++;
        }

        return *(nums.end()-k);
    }

    void update(int pre,int n,vector<int>& nums)
    {
        int maxid=pre,left=2*pre+1,right=2*pre+2;

        if(left<n && nums[left]>nums[maxid]) maxid=left;
        if(right<n && nums[right]>nums[maxid]) maxid=right;

        if(maxid!=pre)
        {
            swap(nums[pre],nums[maxid]);
            update(maxid,n,nums);
        }
    }
};
```