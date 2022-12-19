
![image.png](https://pic.leetcode-cn.com/1ad7417a04c2da936f13ee12d52685b17a954c46aa0956f669d3290fd6a9fcbe-image.png)
```
    static char[] p;
    static int[] dp;
    static int len;
    public  String longestPrefix(String s) {
        p=s.toCharArray();
        dp=new int[p.length];
        len=p.length;
        return s.substring(0,len());
    }
     int len()
    {
        int i=0,j;
        for(j=1; j<len; j++)
        {
            while(p[i]!=p[j]&&i>0)
                i=dp[i-1];
            if(p[i]==p[j])
            {
                i++;
                dp[j]=i;
            }
            else
                dp[j]=0;
        }
        return dp[len-1];
    }
```
