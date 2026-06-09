### 解题思路
就是二分法加点判断，详细见下面代码

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        if(nums[r] < target){
            return len;
        }
        if(nums[l] >= target){
            return 0;
        }
        while(l <= r){
            int mid = (l+r)/2;
            //============ 核心部分 ============
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                if(mid > 0 && nums[mid-1] < target){
                    return mid;
                }
                r = mid - 1;
            }else{
                // nums[mid] < target
                if(mid+1 < len && nums[mid+1] > target){
                    return mid+1;
                }
                l = mid+1;
            }
            //============ 核心部分 ============
        }
        if(nums[l] < target){
            return l+1;
        }else{
            return l;
        }
    }
};
```

### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 64.25% 的用户 
内存消耗 : 6.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户