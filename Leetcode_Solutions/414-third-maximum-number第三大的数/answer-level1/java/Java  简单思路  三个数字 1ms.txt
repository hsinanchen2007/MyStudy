### 解题思路

使用 3个 数字用来 存放 **第一大 第二大 第三大的** 值。

解体思路每次遍历分别找到 最大 第二大 第三大，三次遍历可以合成一次完成。

时间复杂度O(n) 空间复杂度 O(1);

这题的问题在 可能存在重复 和 会有 Integer.MIN_VALUE 的值。Java 写不太方便，无奈用了Long.MIN_VALUE

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {

        long m1 = Long.MIN_VALUE;
        long m2 = Long.MIN_VALUE;
        long m3 = Long.MIN_VALUE;

        for(int k : nums) {

            if (k == m1 || k == m2 || k == m3) continue;

            if (k > m1) {
                m3 = m2;
                m2 = m1;
                m1 = k;
            } else if (k > m2) {
                m3 = m2;
                m2 = k;
            } else if (k > m3) {
                m3 = k;
            }
        }

        if (m3 == Long.MIN_VALUE) return (int)m1;
        return (int)m3;
    }
}
```