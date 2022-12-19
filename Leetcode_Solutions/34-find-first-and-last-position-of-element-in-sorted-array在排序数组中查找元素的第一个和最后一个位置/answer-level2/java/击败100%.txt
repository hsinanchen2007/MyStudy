### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        if(n == 0){
            return new int[]{-1, -1};
        }
        int left = findFirst(nums, target);
        // 左边界就找不到
        if(left == -1){
            return new int[]{-1, -1};
        }
        // 找到的左边界并不是target
        if(nums[left] != target){
            return new int[]{-1, -1};
        }
        // 右边界找比target大的元素的第一个下标
        int right = findFirst(nums, target+1);
        if(right == -1){
            // 最大为target
            if(nums[n-1] == target){
                return new int[]{left, n-1};
            }
        }
        
        return new int[]{left, right-1};



        
    }
    // 定义一个找到大于等于target第一个元素下标的函数
    private int findFirst(int[] nums, int target){
        // 左闭右开的区间
        int lo = 0;
        int hi = nums.length;
        while(hi > lo){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] >= target){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        // 数组中所有元素小于target
        if(lo == nums.length){
            return -1;
        }
        return lo;
    }
}
```