### 解题思路
执行用时 :
4 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
36 MB
, 在所有 Java 提交中击败了
100.00%
的用户

### 代码

```java
class Solution {
    public String freqAlphabets(String s) {
        char[] chs = s.toCharArray();
        int i = chs.length - 1;
        s = "";
        while (i >= 0) {
            if (chs[i] == '#') {
                s = (char) (Integer.valueOf(chs[i - 2] + "" + chs[--i]) + 96) + s;
                i--;
            } else {
                s = (char) (Integer.valueOf(chs[i]+"") + 96) + s;
            }
            i--;
        }
        return s;
    }
}
```