执行结果：
- 执行用时 : 1 ms, 在Find First and Last Position of Element in Sorted Array的Java提交中击败了99.46% 的用户
- 内存消耗 : 40.4 MB, 在Find First and Last Position of Element in Sorted Array的Java提交中击败了92.09% 的用户

步骤：
- 1、通过二分查找找到target存在的区间
- 2、通过类似二分查找的方法分两个区间找到两个边界的target

这样做的优点：
 - 1、对于存在大量重复值的有序数组时间复杂度会快一些
 - 2、最差情况下的时间复杂度依然为O(log n)


```angelscript
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[] {-1, -1};
        int numsLen = nums.length;
        if (numsLen == 0) {
            return res;
        } else if (numsLen == 1) {
            if (target == nums[0]) {
                res[0] = 0;
                res[1] = 0;
                return res;
            }
        }

        int leftP = 0;
        int rightP = numsLen - 1;
        int mid = 0;
        boolean findTargetInFirstLoop = false;
        while (leftP <= rightP) {
            mid = leftP + (rightP - leftP) / 2;
            if (nums[mid] > target) {
                rightP = mid - 1;
            } else if (nums[mid] < target) {
                leftP = mid + 1;
            } else {
                findTargetInFirstLoop = true;
                break;
            }
        }
        if (findTargetInFirstLoop) {
            int leftP1 = leftP;
            int rightP1 = mid;
            int leftP2 = mid;
            int rightP2 = rightP;
            int mid1;
            int mid2;
            //分两个区间查找上界和下界
            while (leftP1 <= rightP1) {
                mid1 = leftP1 + (rightP1 - leftP1) / 2;
                if (nums[mid1] < target) {
                    leftP1 = mid1 + 1;
                } else {
                    if ((mid1 > 0 && nums[mid1 - 1] != target) || mid1 == 0) {
                        res[0] = mid1;
                        break;
                    }
                    rightP1 = mid1 - 1;
                }
            }
            while (leftP2 <= rightP2) {
                mid2 = leftP2 + (rightP2 - leftP2) / 2;
                if (nums[mid2] > target) {
                    rightP2 = mid2 - 1;
                } else {
                    if ((mid2 < numsLen - 1 && nums[mid2 + 1] != target) || mid2 == numsLen - 1) {
                        res[1] = mid2;
                        break;
                    }
                    leftP2 = mid2 + 1;
                }
            }
        }
        return res;
    }
}
```