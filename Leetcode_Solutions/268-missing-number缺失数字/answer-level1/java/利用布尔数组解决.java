### 解题思路
将数组中每个值对应的布尔数组的位置设置为true，然后遍历这个布尔数组，返回为false的元素的位置

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        boolean[] bucket = new boolean[nums.length + 1];
        for (int num : nums) {
            bucket[num] = true;
        }
        for (int i = 0; i < bucket.length; i++) {
            if (!bucket[i]) {
                return i;
            }
        }
        return -1;
    }
}
```