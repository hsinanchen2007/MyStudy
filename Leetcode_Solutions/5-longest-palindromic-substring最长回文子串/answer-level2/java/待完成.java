### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        char[] c = s.toCharArray();
        int len = c.length;
        if(len == 0)    return "";
        boolean[][] dp = new boolean[len][len];
        int ans = 1, temp = 1;
        int begin = 0, end = 0;
        for(int i = 0; i < len; i++)
        {
            dp[i][i] = true;
            int j  = i + 1;
            if(j < len && c[i] == c[j])
            {
                dp[i][j] = true;
                temp = 2;
                if(temp > ans)
                {
                    ans = temp;
                    begin = i;
                    end = j;
                }
            }
        }
        for(int k = 3; k <= len; k++)
        {
            for(int i = 0; i+k-1 < len; i++)
            {
                int j = i + k - 1;
                if(c[i] == c[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    temp = k;
                    if(temp > ans)
                    {
                        ans = temp;
                        begin = i;
                        end = j;
                    }
                }
            }
        }
        return s.substring(begin, end + 1);
    }
}
```