方法一：
- 时间复杂度：最坏情况o(n)，最好情况o(logn)
```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            while(left!=right && nums[left]==nums[right]) right--; //无重复值的解法中添加这行
            int mid=(left+right)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target){
                if(nums[mid]>nums[right] && target<nums[left]) left=mid+1;
                else right=mid-1;
            }else{
                if(nums[mid]<nums[left] && target>nums[right]) right=mid-1;
                else left=mid+1;
            }
        }
        return false;
    }
};
```
方法二：
- 时间复杂度：o(n)，平均时间复杂度高于方法一
- 优点：简洁易懂
```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto x:nums) if(x==target) return true;
        return false;
    }
};
```

> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------

