### 解题思路
利用字符串的indexOf不算作弊吧？

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        boolean result = true;
        char[] schar = s.toCharArray();
        int start = 0;
        for (int i = 0; i < schar.length; i++) {
            int ss = Searchindex(t, start, schar[i]);
            if (ss >= 0) {
                start = ss+1;
            } else return false;
        }
        return result;
    }

    public int Searchindex(String str, int start, char s) {
        return str.indexOf(s, start);
    }
}
```