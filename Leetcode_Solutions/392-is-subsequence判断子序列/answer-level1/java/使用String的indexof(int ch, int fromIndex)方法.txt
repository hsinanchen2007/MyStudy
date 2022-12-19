### 解题思路
使用String的indexOf(int ch, int fromIndex)方法，则只需要遍历一遍就OK了

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] chars = s.toCharArray();
        int j = -1;
        for (int i=0; i<chars.length; i++) {
            j = t.indexOf(chars[i], j + 1);
            if (j == -1) {
                return false;
            }
        }

        return true;
    }
}
```