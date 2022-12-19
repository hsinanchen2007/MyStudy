方法一：利用stl find函数（达不到题目中要求的时间复杂度要求）
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        auto iter=find(nums.begin(), nums.end(), target); //find函数返回一个迭代器，找不到返回nums.end()
        if (iter!=nums.end()) return (iter-nums.begin());
        else return -1;
    }
};
```
方法二：二分查找
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz==0) return -1;
        int left = 0, right = sz-1, mid=0;
        while (left<=right){
            mid = (right+left) / 2;
            if (nums[mid]==target) return mid;
            if (nums[right]==target) return right;  // 如果不加这一语句，遇到[3,1]此类数组会输出错误结果
            else if (nums[mid]>nums[left]){
                if (nums[left]<=target && nums[mid]>target) right = mid-1;
                else left = mid+1;
            }
            else {
                if (nums[mid]<target && nums[right]>=target) left = mid+1;
                else  right = mid-1;;
            }
        }
        return -1;
    }
};
```

