### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public void ReverseString(char[] s) {
        int l=0,r=s.Length-1;
        while(true)
        {
            if(l<r)
            {
                char t=s[l];
                s[l] =s[r];
                s[r]=t;
                l++;
                r--;
            }else{
                break;
            }
        }
    }
}
```