### 复杂度分析
时间复杂度：O(nlogn)
空间复杂度：O(1)
其中 n 为数组长度

### 解题思路
由于该数字出现次数超过数组长度的一半，
那么在排序过后，这个数字必定在数组中间。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
```