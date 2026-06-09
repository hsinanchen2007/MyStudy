### 解题思路
![t.jpg](https://pic.leetcode-cn.com/e6f9a7b73407c6bb60839c52f8dc0bc74456eeeaef6a548adfa78a50959453ba-t.jpg)

思路很简单，从数组0处索引开始向后遍历验证，直到索引bits.length - 1处（由于bites总是以0结尾）
验证的方法：
1. 遇到1则数组索引 += 2，因为1总是能和自己的下一个字符组成一个双字节字符，否则遇到0数组索引 ++ 即可
2. 循环有两个结束条件，即 i == bites.length 或 i == bites.length - 1。但仔细分析这两个条件其实可以合并成一个，因为 i == bites.length结束循环时，根据第一步可知数组倒数第二个元素必为1。因此最后一个必不为一个一比特字符。如果以i == bites.length - 1结束循环，则倒数第二个元素一定为0，（如果不是将以 i == bites.length结束）此时可判定最后一个字符一定为一个一比特字符。因此方法的返回结果可直接写成 i != bites.length.
### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while (i < bits.length - 1)
            if (bits[i] == 1) i += 2;
            else              i++;
        return i != bits.length;
    }
}
```