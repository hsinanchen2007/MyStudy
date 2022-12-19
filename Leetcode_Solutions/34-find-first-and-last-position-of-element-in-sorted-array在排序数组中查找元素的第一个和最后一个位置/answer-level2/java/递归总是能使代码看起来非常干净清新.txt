## 善用递归让代码变得更漂亮

这道题大多数人的解法包含了非常多的 IF... ELSE...

这会让代码变得很繁琐，看起来并不美观，也不便阅读，同时占用行数较多，在现实中占用太多行数，在阅读时无论是对于自己还是阅读者，都会感到异常吃力。

`if...else...` 结构可以优化的方式有很多，其中一种就是使用递归，通过递归的 `return` 语句，让 `else` 消失不见：

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] answer = new int[]{-1, -1};
        if(nums.length == 0 || nums[0] > target || nums[nums.length - 1] < target) return answer;
        /** 寻找左边界 **/
        answer[0] = binarySearch(nums, 0, nums.length, target, true);
        /** 有左边界就寻找右边界 **/
        if(answer[0] != -1) answer[1] = binarySearch(nums, answer[0] + 1, nums.length, target, false);
        if(answer[1] == -1) answer[1] = answer[0];
        return answer;
    }
    
    /**
     * 二分查找目标值，返回目标值在数组中第一次出现的位置或最后一次出现的位置
     * 
     * @param nums 待查找数组
     * @param begIdx 起始索引
     * @param endIdx 结束索引（不包含）
     * @param target 目标值
     * @param isLeft true 查找左边界，false 查找右边界
     * @return 返回其对应边界下标，若无则返回 -1；
     */
    private int binarySearch(int[] nums, int begIdx, int endIdx, int target, boolean isLeft) {
        /** 子数组长度为 0 **/
        if(endIdx - begIdx == 0) return -1;
        /** 子数组长度为 1 **/
        if(endIdx - begIdx == 1) return target == nums[begIdx] ? begIdx : -1;
        /** 中间元素索引 **/
        int midIdx = (endIdx - begIdx) / 2 + begIdx;
        if(nums[midIdx] > target) return binarySearch(nums, begIdx, midIdx, target, isLeft);
        if(nums[midIdx] < target) return binarySearch(nums, midIdx + 1, endIdx, target, isLeft);
        /** 中部元素为目标元素，根据 isLeft 继续二分查找左/右边界 **/
        int result = isLeft ? binarySearch(nums, begIdx, midIdx, target, isLeft) : binarySearch(nums, midIdx + 1, endIdx, target, isLeft);
        return result == -1 ? midIdx : result;
    }
}
```