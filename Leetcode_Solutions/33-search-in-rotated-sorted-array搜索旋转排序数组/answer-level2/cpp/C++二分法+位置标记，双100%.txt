### 解题思路
二分查找，加一个状态量，标记target所在区间（是否在旋转后前半段）

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        bool first_half=nums[0]<=target;
        int left=0,right=nums.size()-1;
        int center=(left+right)/2;
        while (left<right){
            if (nums[center]==target) return center;
            else if ((first_half && (nums[center]>target || nums[center]<nums[0])) || (!first_half && (nums[center]>target && nums[center]<nums[0]))){
                right=center-1;
                center=(left+right)/2;
            }
            else{
                left=center+1;
                center=(left+right)/2;
            }
        }
        return nums[left]==target ? left : -1;  
    }
};
```