### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int h_length = haystack.length(),
            n_length = needle.length();
        
        if(n_length == 0) {
            return 0;
        }

        for(int h = 0, n = 0; h < h_length;) {
            if(haystack.charAt(h) == needle.charAt(n)) {
                h++;
                n++;
                if(n == n_length) {
                    return h - n_length;
                }
        
            } else {
                if(n != 0) {
                    h = h - n + 1;
                    n=0;
                } else {
                    h++;
                    n = 0; 
                }
                
            }
        }
        
        return -1;
    }
}
```