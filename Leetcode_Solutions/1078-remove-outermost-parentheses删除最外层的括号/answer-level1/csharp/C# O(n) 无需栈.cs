```
public class Solution {
    public string RemoveOuterParentheses(string s) {
        if(s==null) return null;
        bool hasOuter = false;
        int outerCount = 0;
        StringBuilder sb = new StringBuilder();
        foreach(char c in s)
        {
            if(c=='(')
            {
                if(!hasOuter)
                    hasOuter = true;
                else
                    sb.Append(c);
                outerCount++;
            }
            if(c==')')
            {
                outerCount--;
                if(outerCount>0)
                {
                    sb.Append(c);
                }else{
                    hasOuter = false;
                }
            }
        }
        return sb.ToString();
    }
}
```
