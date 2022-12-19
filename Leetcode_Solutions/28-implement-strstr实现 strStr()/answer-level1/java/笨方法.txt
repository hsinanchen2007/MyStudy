### 解题思路
利用String的substring()方法,根据needle的长度，将haystack的字符串分区与needle进行比较，若有相等的，直接返回该索引位置。

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int len = needle.length();
        if(len == 0) return 0;
        for(int i = 0; i < haystack.length() - len + 1 ; i ++){
            String str = haystack.substring(i , i + len);
            if(str.equals(needle)) return i;
        }
        return -1;
    }
}
```