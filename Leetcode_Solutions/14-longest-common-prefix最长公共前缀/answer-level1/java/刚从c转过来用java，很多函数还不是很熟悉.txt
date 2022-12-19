### 解题思路
先找到字符串数组中长度最短的字符串，这里有一个报错，我一开始是int minLength = strs[0].length(),但是提交之后说有编译错误，我就换成把字符串数组最后一个字符串作为初始长度minLength，然后可以把字符串数组当成二维数组扫描，横向比较，从第一个字符串的第一个字符开始，如果遍历一遍所有字符串后，该位置的字符都一样，就把这个字符加入到要返回的字符串里面，出现不一样的情况就返回前面得到的公共前缀字符串。

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0)
            return "";
        int minLength = strs[strs.length-1].length();
        for (int i = 0; i < strs.length-1; i++) {
            if(strs[i].length() < minLength)
                minLength = strs[i].length();
        }
        char c;
        StringBuffer str = new StringBuffer("");
        for (int j = 0; j < minLength; j++) {
            c = strs[0].charAt(j);
            for (int i = 1; i < strs.length; i++) {
                if(strs[i].charAt(j) != c)
                    return str+"";
            }
            str.append(c);
        }
        return str+"";
    }
}
```