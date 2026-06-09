### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int StrStr(string haystack, string needle) {
        int l1 = haystack.Length, l2 = needle.Length;
        if(l1 < l2) return  -1;
        else if( l2 == 0) return 0;
        for(int i = 0;i <= l1 - l2; i++)
        {
            if(haystack.Substring(i, l2) == needle)
            {
                return i;
            }
        }

        return -1;
        
    }
}
```