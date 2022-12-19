### 解题思路
参看了题解区的解答思路。

源字符串翻一倍，然后去掉首尾字符，在在里面查找是否存在源串。有的话就是存在重复字符串。没有就是不存在重复字符串了。


### 代码

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String str = s + s;
        str = str.substring(1, str.length()-1);
        if(str.indexOf(s) > -1)
            return true;
        return false;
    }
}
```