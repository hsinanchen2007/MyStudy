### 解题思路
查找每一个字符的首位和末位  返回值相同则没有重复字符串 反之

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for (int i = 0; i < astr.length(); i++) {
            if (astr.indexOf(astr.charAt(i)) != astr.lastIndexOf(astr.charAt(i))) {
                return false;
            }
        }
        return true;
    }
}
```