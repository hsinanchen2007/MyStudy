求出next数组后，取最后位置的值即可...
为啥会放到第四题...
```
class Solution {
    public String longestPrefix(String s) {
        int n=s.length();
        int []next=new int[n+1];
        
        for(int i=2,j=0;i<=n;i++)
        {
            while(j!=0&&s.charAt(i-1)!=s.charAt(j))
            {
                j=next[j];
            }
            if(s.charAt(i-1)==s.charAt(j))
            {
                j++;
            }
           next[i]=j;
        }
        
        return s.substring(0,next[n]);
    }
}
```
