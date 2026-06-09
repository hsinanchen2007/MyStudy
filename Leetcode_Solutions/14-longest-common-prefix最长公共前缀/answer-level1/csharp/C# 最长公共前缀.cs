### 代码
```c#
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
       if(strs.Length==0) return "";

        StringBuilder sb = new StringBuilder("");
        
        for(int i=0;i<strs[0].Length;i++)
        {
            char pre=strs[0][i];
            for(int j=1;j<strs.Length;j++)
            {   
                if(strs[j].Length<=i) {return sb.ToString(); }
                if(strs[j][i]!=pre)
                {
                    return sb.ToString();
                }
            }
            sb.Append(pre);
        }

        return sb.ToString();
    }
}
```