```
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]


/********************************************************************************************
（1）类似双指针法
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        int left,right;
        left=right=-1;
        for(int i=0;i<nums.size();i++)
        {

            if(left==-1&&nums[i]==target)
                left=i;
            if(nums[i]==target)
                right=i;
        }
        res.emplace_back(left);
        res.emplace_back(right);
        return res;
    }
};

/**********************************************************************************************
（2）二分法

思路：对于left=0,right=num.size()-1来说的话，[left,right]为搜索区间，要使while里面的循环（left<=right）结束，那么就必须是[left,mid-1],[mid+1,right]两个区间
所以，若target<nums[mid] 则需要将right=mid-1,若target>nums[mid]，则是left=mid+1,
左边界为right+1,右边界为left-1;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.empty()||nums[nums.size()-1]<target||nums[0]>target) return {-1,-1};

        vector<int> res;
        int left=0,right=nums.size()-1;
        int mid=0;

        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]<target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid-1;
            else
                right=mid-1;
        }
        if(nums[right+1]==target) res.push_back(right+1);
        else res.push_back(-1);
        
        left=0,right=nums.size()-1;
        mid=0;

        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]<target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        if(nums[left-1]==target) res.push_back(left-1);
        else  res.push_back(-1);
        return res;
    }
};

/********************************************************************************************
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int mid=0;
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
        	mid=(left+right)/2;
        	if(nums[mid]==target) break;
	if(nums[mid]<target) left=mid+1;
	else right=mid-1;
        }
        if(left>right) return {-1,-1};
        left=right=mid;
        while(left>0&&nums[left-1]==target) left--;
        while(right<nums.size()-1&& nums[right+1]==target) right++;
        return {left,right};
    }
};

/********************************************************************************************

思路：对于left=0,right=num.size()来说的话，[left,right)为搜索区间（左闭右开），要使while里面的循环（left<right）结束，那么就必须是[left,mid）,[mid+1,right）两个区间
所以，若target<nums[mid] 则需要将right=mid,若target>nums[mid]，则是left=mid+1,

左边界为left,右边界为left-1;


    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            
            if(nums.empty()||nums[nums.size()-1]<target||nums[0]>target) return {-1,-1};

            vector<int> res;
            int left=0,right=nums.size();
            int mid=0;

            while(left<right)
            {
                mid=(left+right)/2;
                if(nums[mid]<target)
                    left=mid+1;
                else if(nums[mid]>target)
                    right=mid;
                else
                    right=mid;
            }
            if(nums[left]==target) res.push_back(left);
            else res.push_back(-1);
            
            left=0,right=nums.size();
            mid=0;

            while(left<right)
            {
                mid=(left+right)/2;
                if(nums[mid]<target)
                    left=mid+1;
                else if(nums[mid]>target)
                    right=mid;
                else
                    left=mid+1;
            }
            if(nums[left-1]==target) res.push_back(left-1);
            else  res.push_back(-1);
            return res;
        }
    };

/**************************************************************************
（3） STL法

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
};
```
