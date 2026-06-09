
```Java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0) return new int[]{-1,-1};
        return new int[]{searchLeft(nums,target),searchRight(nums,target)};
    }
    
    public int searchLeft(int[] nums,int target){
        int left = 0;
        int right = nums.length - 1;
        while(left <= right){
            // 防止溢出
            int mid = left + (right - left)/2;
            if(nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        // 上面的while循环后，最后一次循环 left == mid, right = left - 1 = mid - 1
        // 若有符合要求的target，则会有两种情况：
        // 1. left 和 right 在 target 值的最左索引处的前一位相遇，此时 left 会向右一位，到达最左 target 处,而 right 会停在原地，弹出 while
        // 2. left 和 right 在 target 值的最左索引处相遇，此时 left 不动，到达最左 target 处,而 right 会向左一位，弹出 while
        // 注意：此时的 left 都是处在 target 最左索引处
        // 如果没有符合要求的target，则有三种情况：
        // 1.所有值均小于target，此时，left会在 nums[nums.length-1]处与right相遇，然后left 加 1，跳出循环，此时left == nums.length
        // 2.所有值均大于target，此时right会不断向左，直至 left = right = 0 相遇，此时 right 减 1，跳出循环，此时 left == 0
        // 3.target位于值的中间，但是没有值取到，此时跟有target情况是类似的，最终 left 会停留在比 target 大的第一个数上 
        // 总结上面 5 种情况，left 为 nums.length 时，另其为 nums.length - 1,此时直接判断 nums[left] 即可，若为target则直接返回 left
        // 否则返回 -1
        int pos = (left == nums.length) ? nums.length - 1 : left;
        if(nums[pos] != target) return -1;
        return left;
    }
    
    public int searchRight(int[] nums,int target){
        int left = 0;
        int right = nums.length - 1;
        while(left <= right){
            // 防止溢出
            int mid = left + (right - left)/2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        // 同上分析
        // 最左和最右只有一个区别，就是 left 换成了 right ，nums.length 换成了 -1
        int pos = (right == -1)? 0 : right;
        if(nums[pos] != target) return -1;
        return right;
    }
}
```