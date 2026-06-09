没看题解，自己写出的解法。
第一次发题解，好激动。

## 思路
1. **0～n**的总大小减去序列中数字总和，即可获得缺失的数字。
2. 考虑到使用 **n * (n-1) / 2** 计算总大小时，**n**较大可能会导致值超出Int范围。
3. 所以采用在累加**0～n**的值的同时减去序列中值的方式进行控制。

## 代码实现

优化代码：对序列进行迭代，因为角标**i**从**0**开始，所以累加**i+1**相当于累加**1～n**。

```java []
class Solution {
    public int missingNumber(int[] nums) {
        int count = 0;
        for (int i = 0;i< nums.length;i++) {
            // 先减后加
            count = count - nums[i] + i + 1;
        }
        return count;
    }
}
```
```kotlin []
class Solution {
    fun missingNumber(nums: IntArray): Int {
        var count = 0;
        for (i in nums.indices) {
            // 先减后加
            count = count - nums[i] + i + 1
        }
        return count
    }
}
```
