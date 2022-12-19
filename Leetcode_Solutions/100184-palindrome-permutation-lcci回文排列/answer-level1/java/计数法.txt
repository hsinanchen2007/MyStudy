### 执行结果：*通过*
显示详情 执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 37.2 MB , 在所有 Java 提交中击败了 100.00% 的用户

### 解题思路
核心就是，既然要回文，那么字符出现奇数次的只允许一个单词。其他的只能出现偶数次。
步骤就按照计数的方式。统计出所有字符出现的次数。
最后以此判断即可。


### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        boolean br = s != null && s.length() > 0;
        if (s.length() == 1)
            return br;
        else if (br) {
            /**
             * -128 ,127
             */
            int[] counter = new int[256];
            for (char c : s.toCharArray()) {
                counter[c - (-128)]++;
            }
            int sc = 0;
            for (int i = 0; i < counter.length && sc < 2; i++) {
                sc += ((counter[i] & 1) == 1) ? 1 : 0;
            }
            br = sc < 2;
        }
        return br;
    }
}
```