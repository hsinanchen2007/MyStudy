### 解题思路
假设是从0到n+1的n+1个数，那么数组的和就是n*(n+1)/2
依次减去每个数，最后得到的就是缺失的数


### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int length = nums.length;
        int count = length * (length + 1) / 2;
        for (int i = 0; i < nums.length; i++) {
            count -= nums[i];
        }
        return count;
    }
}
```