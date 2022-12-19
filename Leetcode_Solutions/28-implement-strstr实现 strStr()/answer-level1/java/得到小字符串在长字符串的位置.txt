### 解题思路
用滑动窗口法：将小字符串的大小作为窗口，在大字符串滑动比较，如果相等则返回索引位置

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
    int hl=haystack.length();
    int nl=needle.length();
    for(int i=0;i<hl-nl+1;i++){
        if(haystack.substring(i,i+nl).equals(needle)){return i;}//d重点，字符串比较用equals，不用==
    }
    return -1;
    }
}
```