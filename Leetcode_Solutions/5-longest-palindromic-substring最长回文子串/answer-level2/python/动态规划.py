dp[i][j] 表示第i个字符到第j个字符中最长子串的长度。
dp[i][j]有两种情况：
dp[i][j]=dp[i-1][j-1]（s[i]!=s[j]）
dp[i][j]=dp[i-1][j-1]+2（s[i]==s[j]&&dp[i-1][j-1]=j-i-1）

dp[i-1][j-1]=j-i-1是什么意思？（j-1）-（i-1）+1=j-i-1
dp[i-1][j-1]表示的最长子串长度和它的长度一样长，表示整个i-1到j-1之间的子串是回文子串

class Solution {
    public String longestPalindrome(String s) {
        if (s.length()<2) return s;
        int[][] dp = new int[s.length()+1][s.length()+1];
        int maxLength=0,start=0,end=0;
        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i <=j; i++) {
                if (i==j)
                {
                    dp[i][j]=1;
                    if (dp[i][j]>maxLength)
                    {
                        start=i;
                        end=j;
                        maxLength=dp[i][j];
                    }
                }
                else if (j-i==1)
                {
                    if (s.charAt(i)==s.charAt(j))
                    {
                        dp[i][j]=2;
                        if (dp[i][j]>maxLength)
                        {

                            start=i;
                            end=j;
                            maxLength=dp[i][j];
                        }
                    }
                    else
                        dp[i][j]=0;
                }
                else if (s.charAt(i)==s.charAt(j)&&dp[i+1][j-1]==j-i-1)
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                    if (dp[i][j]>maxLength)
                    {

                        start=i;
                        end=j;
                        maxLength=dp[i][j];
                    }
                }
                else
                    dp[i][j]=dp[i+1][j-1];
            }
        }
        return s.substring(start,end+1);
    }
}