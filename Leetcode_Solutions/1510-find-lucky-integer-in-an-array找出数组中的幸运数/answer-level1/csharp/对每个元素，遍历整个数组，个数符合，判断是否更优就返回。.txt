### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int FindLucky(int[] arr) {
        int i = 0;int c=-1;
        foreach (int a in arr)
        {
            foreach(int b in arr)
            {
                if(a==b)
                {
                    i++;
                }
            }
            if(a==i&&a>c)
            {
                c=a;
            }
            i=0;
        }
        return c;
    }
}
```