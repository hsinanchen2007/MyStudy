### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if("".equals(needle)){
            return 0;
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while(k < haystack.length() - needle.length() + 1){
            if(haystack.charAt(i) == needle.charAt(j)){
                if(j == needle.length() - 1){
                    return k;
                }
                i++;
                j++;
            } else {
                j = 0;
                i = ++k;
            }
        }
        return -1;
    }
}
```