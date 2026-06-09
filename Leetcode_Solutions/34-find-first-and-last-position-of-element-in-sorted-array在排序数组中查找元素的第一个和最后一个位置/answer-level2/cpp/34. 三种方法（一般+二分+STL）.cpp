方法一
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1,end=-1;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(start==-1&&nums[i]==target) start=i;
            if(nums[i]==target) end=i;
        }
        res.emplace_back(start);
        res.emplace_back(end);
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0f3425c26490d0aaa9c525a009e94bfb70bceaec57fa5189ae9e50b715ee6d7d-image.png)
方法二、二分查找
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size(),mid;
        vector<int> res;
        while(left<right){    //找左边界
            mid=left+(right-left)/2;
            if(nums[mid]==target) right=mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        if(left==nums.size()||nums[left]!=target) return res={-1,-1};
        if(nums[left]==target) res.emplace_back(left);
        right=nums.size();
        while(left<right){    //找右边界
            mid=left+(right-left)/2;
            if(nums[mid]==target) left=mid+1;
            else if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        if(nums[right-1]==target) res.emplace_back(right-1);
        return res;
    }
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int left=0,right=nums.size(),mid;
    //     vector<int> res;
    //     while(left<right){ 
    //         mid=left+(right-left)/2;
    //         if(nums[mid]==target) right=mid;
    //         else if(nums[mid]<target) left=mid+1;
    //         else right=mid;
    //     }
    //     if(left==nums.size()) return res={-1,-1};
    //     else if(nums[left]==target) res.emplace_back(left);
    //     else if(nums[left]!=target) return res={-1,-1};
    //     left=0,right=nums.size();
    //     while(left<right){ 
    //         mid=left+(right-left)/2;
    //         if(nums[mid]==target) left=mid+1;
    //         else if(nums[mid]<target) left=mid+1;
    //         else right=mid;
    //     }
    //     if(right==0) return res={-1,-1};
    //     else if(nums[right-1]==target) res.emplace_back(right-1);
    //     else if(nums[right-1]!=target) return res={-1,-1};
    //     return res;
    // }
};
```
![image.png](https://pic.leetcode-cn.com/a927522f1613016d23826403eb362d0959f858eabad481f4eb06f4065ca52a19-image.png)
方法三 STL
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //返回第一个大于等于target的迭代器
        auto left = lower_bound(nums.begin(), nums.end(), target);
        //返回第一个大于target的迭代器
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if(left == right) return {-1,-1};
        return {left-nums.begin(), right-nums.begin()-1};
    }
```
