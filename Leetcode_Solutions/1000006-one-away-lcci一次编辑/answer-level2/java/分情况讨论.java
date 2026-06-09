### 解题思路
不整花里胡哨的直接做，根据两个字符串 first 和 second 的长度进行分情况讨论：
1. `Math.abs(first.length() - second.length()) >= 2`时，咋都不可能只一次操作使两者相同；
2. first 和 second 长度相差 1，通过`substring()`方法去掉同一位置第一个不一样的字符，此时若两者相等，返回`true`，否则返回`false`；
3. 长度相同时，将遍历到的第一个不同字符替换，若两者相同返回`true`，否则返回`false`。

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        if(Math.abs(first.length() - second.length()) >= 2) return false;
        int[] f = new int[26],s = new int[26];
        if(first.length() - second.length() == 1) {
            for(int i = 0;i < second.length();i++) {
                if(first.charAt(i) != second.charAt(i)) {
                    String str = first.substring(0,i) + first.substring(i + 1,first.length());
                    if(str.equals(second)) return true;
                    return false;
                }
            }
        }
        else if(first.length() - second.length() == -1) {
            for(int i = 0;i < first.length();i++) {
                if(first.charAt(i) != second.charAt(i)) {
                    String str = second.substring(0,i) + second.substring(i + 1,second.length());
                    if(str.equals(first)) return true;
                    return false;
                }
            }
        }
        else {
            for(int i = 0;i < first.length();i++) {
                if(first.charAt(i) != second.charAt(i)) {
                    StringBuilder sb = new StringBuilder(first);
                    sb.setCharAt(i,second.charAt(i));
                    if(sb.toString().equals(second)) return true;
                    return false; 
                }
            }
        }
        return true;
    }
}
```