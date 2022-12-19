### 解题思路
读懂题目是关键，读懂了，写代码就很简单了。

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int size = 0;
        for (int i = 0; i < nums.length; i += 2) {
            size += nums[i];
        }
        int[] results = new int[size];

        int index = 0;
        for (int i = 0; i < nums.length; i += 2) {
            int count = nums[i];
            int num = nums[i + 1];
            while (count > 0) {
                results[index++] = num;
                count--;
            }
        }
        return results;
    }
}
```