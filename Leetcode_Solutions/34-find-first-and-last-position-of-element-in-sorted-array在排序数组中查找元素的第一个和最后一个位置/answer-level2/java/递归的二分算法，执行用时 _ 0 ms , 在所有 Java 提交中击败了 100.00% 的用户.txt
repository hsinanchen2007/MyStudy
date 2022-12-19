### 解题思路
如果target == nums[mid]，更新左右端的值，因为可能存在重复，继续搜索两侧。
否则只搜一侧即可。

### 代码

```java
class Solution {
    int begin = Integer.MAX_VALUE;
    int end = Integer.MIN_VALUE;

    public int[] searchRange(int[] nums, int target) {
        digui(nums, target, 0, nums.length-1);
        if(begin == Integer.MAX_VALUE || end == Integer.MIN_VALUE) return new int[]{-1,-1};
        return new int[]{begin, end};
    }

    public void digui(int[] nums, int target ,int l, int r){
        if(l > r) return;
        int mid = l + (r-l)/2;
        if(target == nums[mid]){
            processResult(mid);
            digui(nums, target, mid + 1, r);
            digui(nums, target, l, mid -1);
        } else if (target > nums[mid]) {
            digui(nums, target, mid + 1, r);
        } else {
            digui(nums, target, l, mid -1);
        }
    }

    public void processResult(int pos){
        if(pos < begin) begin = pos;
        if(pos > end) end = pos;
    }
}
```