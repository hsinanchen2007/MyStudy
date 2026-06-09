## 思路 
二分 分别查找左右边界。

## 细节


#### 1：nums[mid] 和target时左右边界的移动
**求左边界(low bound) **
nums[mid] >= target  :  right = mid
nums[mid] <  target  :  left = mid + 1
求左边界,nums[mid] == target时，不能调整left指针，因为这样可能会漏掉更左侧的目标。

**求右边界(up bound)** 
nums[mid] <= target  :  left = mid
nums[mid]  > target  :  right = mid - 1
求右边界，nums[mid] == target时，不能调整right指针，因为这样可能会漏掉更右侧的目标。

#### 2：中间节点选择
**求左边界(low bound)**
mid = (left + right)>>1;
**求右边界(up bound)** 
mid = (1 + left + right)>>1;
上述区分是为了避免 left, right 直接相邻时可能出现死循环的情况。


## 代码
```
class Solution {
private:
    int low_bound(const vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)>>1;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return (nums[left] == target)?left:-1;
    }
    int up_bound(const vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = (1 + left + right)>>1;
            if(nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        return (nums[left] == target)?left:-1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.resize(2, -1);
        if(nums.empty()){
            return ans;
        }
        ans[0] = low_bound(nums, target);
        if(ans[0] == -1){
            return ans;
        }
        ans[1] = up_bound(nums, target);
        return ans;
    }
};
```

## 参考
算法竞赛 进阶指南 0x04 二分