### 解题思路
如题目中说的: "在数组中任意位置砍一刀，一定有一边是有序的"。
详细看代码中的注释
此外注意，对于target不一定在数组的存在的情况，应该是while(l <= r)而不是while(l < r)
比如[1,2], target = 2。显然是需要判断的l == r的情况的

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1, l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                //[mid,r] is non-sorted, [l, mid] is sorted
                // 说明数组一定不是sorted，只要不是sorted必定有A[l] > A[r]
                if(target == nums[mid]){
                    return mid;
                }else if(target > nums[mid]){
                    // A[mid] > A[l]，说明target只可能在mid的右边
                    l = mid+1; 
                }else{//target < nums[mid]
                    if(target > nums[r]){
                        // 说明只可能在[l,mid]中，[l,mid]为sorted，直接二分查找
                        return searchSortedArray(nums, l, mid-1, target);
                    }else if(target == nums[r]){
                        return r;
                    }else{
                        // target < nums[r]
                        // 说明只可能在[mid, r]
                        l = mid + 1;
                    }
                }
            }else{
                //[mid, r] is sorted
                if(target >= nums[mid] && target <= nums[r]){
                    return searchSortedArray(nums, mid, r, target);
                }else{
                    r = mid - 1;
                }
            }
        }
        return res;
    }
    int searchSortedArray(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 87.22% 的用户 
内存消耗 : 6.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户