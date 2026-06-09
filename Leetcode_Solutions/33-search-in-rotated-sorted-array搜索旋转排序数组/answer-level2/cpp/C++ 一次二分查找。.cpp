### 解题思路
使用一次二分查找。mid和target一上一下是特例需要单独处理。
![捕获.PNG](https://pic.leetcode-cn.com/c13af8753cab993696219fcf10626645cb77ddb2afc0e00afe81502f5bebea52-%E6%8D%95%E8%8E%B7.PNG)

### 代码
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(right-left)/2+left;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target) {
                if(nums[mid]>=nums[0]&&target<nums[0])
                    left=mid+1;
                else
                    right=mid-1;
            }
            else {
                if(nums[mid]<nums[0]&&target>=nums[0])
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        return -1;
    }
};
```