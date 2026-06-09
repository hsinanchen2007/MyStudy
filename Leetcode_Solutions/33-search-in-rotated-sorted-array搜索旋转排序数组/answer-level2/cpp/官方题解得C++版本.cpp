### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;
    if(nums.size()==1){
        if(nums[0]==target)
            return 0;
        return -1;
    }
    int min_nod=0;
    min_nod=findminnode(nums);//找到最小元素脚标
    if (target<=nums[nums.size()-1])//判断目标应该在那部分并在该区间查找
        return findpos(nums,min_nod,nums.size()-1,target);
    else
        return findpos(nums,0,min_nod-1,target);
    }
    int findminnode(vector<int>& nums)
    {
        if(nums[0]<nums[nums.size()-1])
            return 0;
        int lo=0;
        int mid=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]>nums[mid+1])
                return mid+1;
            if(nums[mid]<nums[lo])
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
    int findpos(vector<int>& nums,int dow,int up,int target)
    {
        int lo=dow;
        int hi=up;
        int mid=0;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                lo=mid+1;
            else  
                hi=mid-1;
        }
        if(nums[lo]==target)
            return lo;
        return -1;
    }
};
```