### 解题思路
从左往右每次获取一个字符，需要对比的字符集是从当前下标+1之后的所有字符，当前下标之前的字符已经和当前字符对比过了，不需要再次对比。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        long lenght = astr.length();
        for (int i = 0; i < astr.length() - 1; i++) {
            for (int j = i+1; j < astr.length(); j++) {
                char ic = astr.charAt(i);
                char jc = astr.charAt(j);
                if (ic == jc) {
                    return false;
                }
            }
        }
        return true;
    }
}
```