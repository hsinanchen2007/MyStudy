### 解题思路
执行用时 :6 ms, 在所有 Java 提交中击败了97.36%的用户
内存消耗 :37.6 MB, 在所有 Java 提交中击败了96.30%的用户
还以为我的会很慢呢，😁

### 代码

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        for (int i = len / 2; i > 0; i--) {
            //i是步长，肯定会在一半内的
            //ABC是答案的话，那ABCABC也是答案，遍历到成立的就返回，否则继续遍历
            if (len % i == 0) {
                int end = i;
                //end是每一步长下的字符串
                while (s.substring(0, i).equals(s.substring(end, end + i))) {
                    end += i;
                    if (end == s.length())
                        return true;
                }
            }
        }
        return false;
    }
}
```