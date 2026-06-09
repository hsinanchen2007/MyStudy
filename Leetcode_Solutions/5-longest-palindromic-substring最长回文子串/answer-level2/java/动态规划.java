### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        //特殊情况
        if(s.length() < 2){
            return s;
        }

        boolean[][] dp = new boolean[s.length()][s.length()];
        int start = 0;
        int end = 0;
        int maxLen = 1;

        //初始化
        for(int ptr1 = 0; ptr1 < s.length(); ptr1++){
            dp[ptr1][ptr1] = true;
            if(ptr1 < s.length() -1){
                dp[ptr1][ptr1 + 1] = s.charAt(ptr1) == s.charAt(ptr1 + 1);
                if(dp[ptr1][ptr1 + 1]) {
                    maxLen = 2;
                    start = ptr1;
                    end = ptr1 + 1;
                }
            }    
        }
        
        //状态转移
        for(int count = 1; count < s.length() - 1; count++) {
            int len = count + 2;
            for(int ptr1 = 0; ptr1 < s.length() - 1 - count; ptr1++) {
                 dp[ptr1][ptr1 + count + 1] = (s.charAt(ptr1) == s.charAt(ptr1 + count + 1)) && dp[ptr1 + 1][ptr1 + count];

                 if(len > maxLen && dp[ptr1][ptr1 + count + 1]) {
                     maxLen = len;
                     start = ptr1;
                     end = ptr1 + count + 1;
                 }
            }
        }
         
        return s.substring(start, end + 1); 
    }
}
```