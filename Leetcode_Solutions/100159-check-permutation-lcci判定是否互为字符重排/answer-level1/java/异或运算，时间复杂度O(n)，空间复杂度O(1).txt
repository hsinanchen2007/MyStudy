### 解题思路
因为异或运算的特点是：相同的两个值的运算结果为0，并且满足交换律。所以用异或计算两个字符串中所有字符。如果最终结果是0的话，说明两个字符串中所有的字符都有对应出现。时间复杂度O(n),空间复杂度O(1)
![image.png](https://pic.leetcode-cn.com/bc9b9b285bb1ac14ccdd801e83e4d0e425bac978669d7ac354ab7976a891a2f8-image.png)

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1 == null || s2 == null) {
            return false;
        }
        int length = s1.length();
        if (length != s2.length()) {
            return false;
        }
        int result = 0;
        char[] s1Char = s1.toCharArray();
        char[] s2Char = s2.toCharArray();
        for (int i = 0; i < s1Char.length; i++) {
            result = result ^ s1Char[i] ^ s2Char[i];
        }
        return result == 0;
    }
}
```