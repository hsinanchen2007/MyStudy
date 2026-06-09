### 解题思路
简单的二分法，我用的是递归方法

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
        {
            vector<int> re={-1,-1};
            return re;
        }
        vector<int> re;
        re.push_back(nums.size());
        re.push_back(-1);
        find(nums,target,0,nums.size()-1,re);
        if(re[0]==nums.size() && re[1]==-1)
        {
            re[0]=-1;
            re[1]=-1;
        }
        return re;
    }
    void find(vector<int>& nums, int target,int low,int high,vector<int> & re)
    {
        if(low==high )
        {
            if (nums[low]==target)
            {
                if(low<=re[0])
                    re[0]=low;
                if(low>=re[1])
                    re[1]=low;
            }
                
        }
        else if(low==high-1)
        {
            if(nums[low]==target)
            {
                if(low<=re[0])
                    re[0]=low;
                if(low>=re[1])
                    re[1]=low;
            }
            if(nums[high]==target)
            {
                if(high<=re[0])
                    re[0]=high;
                if(high>=re[1])
                    re[1]=high;
            }
        } 
        else 
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {   
                if(mid<=re[0])
                    re[0]=mid;
                if(mid>=re[1])
                    re[1]=mid;
                find(nums,target,low,mid-1,re);
                find(nums,target,mid+1,high,re);
            }
            else if(nums[mid]>target)
            {
                find(nums,target,low,mid-1,re);
            }
            else if (nums[mid]<target)
            {
                find(nums,target,mid+1,high,re);
            }
        } 
    }
};
```