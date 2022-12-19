### 解题思路
从前面开始会比较慢，直接从最后往前，碰到空格，弹出i；如果到最前面了都没有空格，那么直接返回整个字符串的长度；
如果中间有空格，就返回字符串长度减去i的值。

执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :35.6 MB, 在所有 Java 提交中击败了93.30%的用户

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int length = s.length();
        if(length == 0 || s.equals(null))
            return 0;
        int i = length - 1;
        while (i >= 0 && s.charAt(i) != ' '){
            i--;
        }
        if(i == -1)
            return length;
        else
            return length - 1 - i;
    }
}
```