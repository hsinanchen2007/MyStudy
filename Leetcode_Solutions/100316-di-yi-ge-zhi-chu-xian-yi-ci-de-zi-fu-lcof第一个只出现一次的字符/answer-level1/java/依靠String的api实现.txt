### 解题思路

遍历字符串，然后判断每个字符的第一次出现位置和最后一次出现位置是否相同。

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(null == s || "" == s) return ' ';
        char[] cs = s.toCharArray();
        for(int i = 0; i < cs.length; i++){
            if(s.indexOf(cs[i]) == s.lastIndexOf(cs[i]))
                return cs[i];
        }
        return ' ';
    }
}
```