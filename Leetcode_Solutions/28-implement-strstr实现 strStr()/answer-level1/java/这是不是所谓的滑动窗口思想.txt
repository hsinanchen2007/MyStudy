### 解题思路

执行用时 :1 ms, 在所有 Java 提交中击败了78.48% 的用户

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        
        if(needle.equals("")) {
            return 0;
        }
        int len1 = haystack.length();
        int len2 = needle.length();

        if(len2>len1){
            return -1;
        }

        for(int i=0; i<=len1-len2;i++){
            String s = haystack.substring(i, i+len2);
            if(s.equals(needle)) {
                return i;
            }
        }
        return -1;
    }
}
```