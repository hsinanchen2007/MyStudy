### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int strStr(String haystack,String needle){
        if (needle.length()==0) return 0;
        return strStrs(haystack,needle,0);
    }
    public int strStrs(String haystack,String needle,int m){
        if (haystack.length()<m+needle.length()) return -1;
        if (haystack.substring(m,m+needle.length()).equals(needle))
            return m;
        else {
            return strStrs(haystack,needle,m+1);
        }
    }
}
```