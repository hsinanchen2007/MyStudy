### 解题思路
使用manacher的方法实现，O(n)的时间复杂的。动态规划和穷举等方法都是O(n^2)的复杂度，时间超时。
manacher的核心思想是使用之前的中心点算出的重复半径来估算新的位置的重复半径。
### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s==null ||s.length()==0)
        {
            return "";
        }

        //添加#
        int nslen = 2*s.length()+1;
        String[] ns = new String[nslen];
        ns[0]= "#";
        for(int i = 0 ; i<s.length();i++)
        {
            ns[2*i+1]=s.substring(i,i+1);
            ns[2*i+2] = "#";
        }


        int maxLen=0;
        int maxLoc=0;
        int mx = 0;
        int id = 0;
        int[]p = new int[nslen];
        for(int i =0;i<nslen;i++)
        {
            if(i<mx)
            {
                p[i] = Math.min(p[2*id-i],mx-i);
            }
            else
            {
                p[i]=1;
            }
            while(i-p[i]>=0&&i+p[i]<nslen&&ns[i-p[i]].equals(ns[i+p[i]]))
            {
                p[i]=p[i]+1;
            }
            if(p[i]+i>mx)
            {
                id = i;
                mx = p[i]+i;
            }
            if(p[i]-1>maxLen)
            {
                maxLen = p[i]-1;
                maxLoc = i;
            }
        }

        int start = (maxLoc-1)/2-(maxLen-1)/2;
        int end = start + (maxLen);
        return s.substring(start,end);
    }
    
}
```