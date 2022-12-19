### 解题思路
两种特殊情况，子字符串为空，直接返回0；原字符串为空且子字符串不为空，直接返回-1。

两层循环，第一层从开头到最大可能的位置；用charAt获取String的每一个char，然后分别比较。

突然发现这思路没啥好说的。。。。。

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length() == 0)
            return 0;
        else if (haystack.length() == 0)
            return -1;
        
        
        for(int i = 0; i < haystack.length() - needle.length() + 1; ++i) {
            for(int j = 0; j < needle.length(); j++) {
                if(haystack.charAt(j+i) != needle.charAt(j))
                    break;
                if(j == needle.length() - 1)
                    return i;
            }
         }
        
        return -1;
    }
}
```