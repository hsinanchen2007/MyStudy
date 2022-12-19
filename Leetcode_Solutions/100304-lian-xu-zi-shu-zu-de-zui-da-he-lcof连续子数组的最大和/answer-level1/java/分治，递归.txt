### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return sumRec(nums, 0, nums.length - 1);
    }

    // 分治
    public int sumRec(int[] nums, int left, int right) {
        if (left == right) {
            return nums[left]; 
        }
        int mid = (left + right) / 2;
        int leftSum = sumRec(nums, left, mid);
        int rightSum = sumRec(nums, mid + 1, right);
        int maxLeftBorderSum = nums[mid], leftBorderSum = 0;
        for (int i = mid; i >= left; i--) {
            leftBorderSum += nums[i];
            if (leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        }
        int maxRightBorderSum = nums[mid+1], rightBorderSum = 0;
        for (int i = mid + 1; i <= right; i++) {
            rightBorderSum += nums[i];
            if (rightBorderSum > maxRightBorderSum) {
                maxRightBorderSum = rightBorderSum;
            }
        }
        return Math.max(Math.max(leftSum, rightSum), maxLeftBorderSum + maxRightBorderSum);
    }
}
```