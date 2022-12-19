### 解题思路
系统方法indexOf不香吗？？？

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) return -1;
        return haystack.indexOf(needle);
    }
}
```