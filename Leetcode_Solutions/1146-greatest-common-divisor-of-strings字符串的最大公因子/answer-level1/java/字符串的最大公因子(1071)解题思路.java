### 解题思路
根据题意，判断Str1和Str2如果有最大公约数的话，Str1一定是以Str2为开始的字符串。所以如果Str1的长度小于Str2，二者翻转一下。我们先判断一下Str1是否以Str2为开始，如果是的话，就从以Str1.substring(Str2.length())开始继续和Str2比较。
直到Str1的长度为0或是Str1不以tr2为开始结束。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        if(len1 == 0) 
            return str2;
        if(len1 < len2)
            return gcdOfStrings(str2, str1);
        if(!str1.startsWith(str2))
            return "";
        return gcdOfStrings(str1.substring(len2,len1), str2); 
    }
}
```