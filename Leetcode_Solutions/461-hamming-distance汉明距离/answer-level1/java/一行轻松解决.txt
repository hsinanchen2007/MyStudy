### 解题思路
异或运算：相同的为0，不同的为1
将两个数做异或运算，然后计算1的个数即是答案。


[个人博客地址](http://47.101.136.180/)

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
```