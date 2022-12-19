### 解题思路
1.先判断两个字符串的长度是否一致，不一致的话直接返回false
2.定义一个常量result接收每次异或的值
3.因为题目设定s1和s2的长度都不超过100，所以两次循环也很快
4.如果s1和s2的字符都一致，那么异或的结果肯定是0，返回true，反之就返回false
### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        //判断字符串s2是否是s1的乱序
        //思路 直接看s2是否与s1长度一致，并且字符一样
        if (s1.length() != s2.length()) {
            return false;
        }

        //用异或，如果s1和s2里面的字符一样，那么全部字符异或后，结果应该是0
        int result = 0;
        for (int i = 0; i < s1.length(); i++) {
            result ^= s1.charAt(i);
        }
        for (int i = 0; i < s2.length(); i++) {
            result ^= s2.charAt(i);
        }
        if (result == 0) {
            return true;
        } else {
            return false;
        }
    }
}
```