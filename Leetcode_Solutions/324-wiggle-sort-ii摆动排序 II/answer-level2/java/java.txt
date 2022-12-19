### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void wiggleSort(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }

        Arrays.sort(nums);
        int length = nums.length;
        int[] sortedNums = new int[length];
        int index = 0;
        int window = length / 2;
        int mid = (length - 1) / 2;
        for (int i = length - 1; i > mid; i--) {
            sortedNums[index++] = nums[i - window];
            sortedNums[index++] = nums[i];
        }
        if (length % 2 == 1) {
            sortedNums[index] = nums[0];
        }

        System.arraycopy(sortedNums, 0, nums, 0, length);
    }
}
```