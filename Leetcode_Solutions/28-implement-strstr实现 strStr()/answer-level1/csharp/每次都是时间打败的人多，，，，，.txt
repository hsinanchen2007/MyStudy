出一个错加一个if哈哈
```
public class Solution {
    public int StrStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(needle.Length>haystack.Length) return -1;
        bool inFull = false;
        for(int i = 0; i<haystack.Length;i++)
        {
            if(haystack[i] == needle[0])
            {
                inFull = true;
                if(i+needle.Length>haystack.Length) return -1;
                for(int j = 0; j<needle.Length;j++)
                {
                    if(haystack[i+j] != needle[j])
                    {
                        inFull = false;
                    }
                        
                }
                 if(inFull)
                return i;
            }
           
        }
        return -1;
    }
}
```
