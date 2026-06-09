![image.png](https://pic.leetcode-cn.com/61013491a42bbef2c177e16939ecf17d286166b1584f3a24908857afc83308bf-image.png)





```C++ []
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size();
        if(target<=nums[0])
        {nums.insert(nums.begin(),target);
        return 0;}
        while(left<right-1)
        {
            int medium=(left+right)/2;
            if(nums[medium]>target)
                right=medium;
            else if(nums[medium]<target)
                left=medium;
            else 
                return medium;
        }
        nums.insert(nums.begin()+left,target);
        return left+1;
    }
};
```
