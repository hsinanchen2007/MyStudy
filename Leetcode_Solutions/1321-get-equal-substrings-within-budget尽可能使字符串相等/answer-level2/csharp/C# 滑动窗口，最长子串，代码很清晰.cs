```
public class Solution {
    public int EqualSubstring(string s, string t, int maxCost) {
           int[] cnt=new int[s.Length];
           for(int i=0;i<s.Length;i++)
           {
               cnt[i]=Math.Abs(s[i]-t[i]);
           }
           int res=0;
           int left=0;
           int right=0;
           int cur=0;
           while(right<s.Length)
           {
               cur+=cnt[right];
               if(cur<=maxCost)
               {
                   //符合题意
                   res=Math.Max(res,right-left+1);
                   right++;
               }
                else
               {
                   cur-=cnt[left];
                   left++;
                   right++;
               }
           }
           return res;
    }
}
```
