```
class Solution {
    public int search(int[] nums, int target) {
        if (nums == null)
            return -1;
        int length = nums.length;
        if (length == 0)
            return -1;
        if (length == 1)
            return nums[0] == target? 0: -1;
        return rangeSearch(nums, target, 0, length -1);
        
    }
    
    private int rangeSearch(int[] nums, int target, int start, int end) {
        int resultIndex = -1;
        if (start == end - 1 || start == end) {
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
            return resultIndex;
        }
        int middle = (start + end) / 2;
        if (nums[start] < nums[middle]) {
            int[] newNums = Arrays.copyOfRange(nums, start, middle + 1);
            resultIndex = Arrays.binarySearch(newNums, target);
            if (resultIndex < 0)//没有找到
                return rangeSearch(nums, target, middle, end);
            resultIndex += start;//Arrays.binarySearch返回的是target在newNums中的index，故要更新
        } else {
            int[] newNums = Arrays.copyOfRange(nums, middle, end + 1);
            resultIndex = Arrays.binarySearch(newNums, target);
            if (resultIndex < 0)//没有找到
                return rangeSearch(nums, target, start, middle);
            resultIndex += middle;//Arrays.binarySearch返回的是target在newNums中的index，故要更新
        }
        return resultIndex;
    }
}
```
# 基本思路：
看到题目说O(logn)很自然想到二分法，注意到有如下规律：
1. nums[start] < nums[middle]时 start~middle的数组是已经排好序了的，直接调用Arrays的binarySearch方法去找，如果没有找到，那么以相同算法去寻找middle ~ end
2. nums[start] > nums[middle]时 middle~end的数组已经排好序，直接二分查找target，如果没有找到，那么以相同算法去寻找start ~ middle

另外需要注意递归的终止条件，如果最后都没有找到target则返回-1