### 解题思路
一个字符串，空格分隔，求最后字符串长度
分析可知，给定的限制是一个字符串，会存在首尾有空格的情况，所以先trim()去除首尾空格。
最后一个字符串的长度，其实就是字符串去除首尾空格后的长度-1，得出整个字符串最大索引值，再用最大索引值-最后一个空格所在的索引，即是最后一个字符串的长度


### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int num = s.length() -1 - s.lastIndexOf(" ");
        return num;


    }
}
```