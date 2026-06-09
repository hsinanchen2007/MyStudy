### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0)
            return "";

        int strLen = s.length();
        int left = 0;
        int right = 0;
        int maxStart = 0;
        int maxLen = 0;
        int len = 1;

        for(int i=0;i<strLen;i++){
            left = i - 1;
            right = i + 1;
            while(left >= 0 && s.charAt(left) == s.charAt(i)){
                left--;
                len++;
            }

            while(right < strLen && s.charAt(right) == s.charAt(i)){
                right++;
                len++;
            }
            while(left >= 0 && right < strLen && s.charAt(right) == s.charAt(left)){
                right++;
                left--;
                len+=2;
            }

            if(len > maxLen){
                maxLen = len;
                maxStart = left + 1;
            }
            len = 1;
        }  
        return s.substring(maxStart,maxStart+maxLen);  
    }
}
```