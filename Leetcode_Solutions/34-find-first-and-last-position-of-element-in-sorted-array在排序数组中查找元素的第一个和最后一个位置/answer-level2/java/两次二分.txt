### 解题思路
两次二分拿到下界和上界下标。对二分算法进行以下修改即可：若要找下界，则每次二分前判断当前nums[start]是否等于target, 
若要找上界，则每次二分前判断当前nums[end]是否等于target；若在二分时发现nums[mid] = target，记录mid下标给idx，若
当前要找下界，则令end = mid - 1, 即继续找可能存在的更小的下标；否则令start = mid + 1，即继续找可能存在的更大的下标。

### 代码

```java
class Solution {
  public int[] searchRange(int[] nums, int target) {
        int start_idx = binarySearch(nums, 0, nums.length - 1, target, true);
        if(start_idx == -1){
            return new int[]{-1, -1};
        }
        int upper_idx = binarySearch(nums, 0, nums.length - 1, target, false);
        return new int[]{start_idx, upper_idx};
    }

    public int binarySearch(int[] nums, int start, int end, int target, boolean isLower){
        int idx = -1;
        while(start <= end){
            if(nums[start] == target && isLower){
                return start;
            }

            if(nums[end] == target && !isLower){
                return end;
            }

            int mid = (start + end) / 2;

            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                idx = mid;
                if(isLower){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return idx;
    }
}
```