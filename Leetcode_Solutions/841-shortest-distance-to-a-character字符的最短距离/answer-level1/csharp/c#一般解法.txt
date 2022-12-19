### 解题思路
一般解法，等待大神提供更好的思路
首先拿到所有目标字符的索引。
然后遍历字符串，
如果当前字符的索引比目标集合中最小值小，那么一定是目标集合最小索引减去当前当前索引；
如果当前字符的索引比目标集合中最大值打，那么一定是当前索引减去目标集合最大的索引；
如果在目标集合最小索引与最大索引中间的话，遍历目标索引集合，依次判断绝对值，取出最小值。
### 代码

```csharp
public class Solution {
    public int[] ShortestToChar(string S, char C) {
        List<int> temp=new List<int>();
        int[] result=new int[S.Length];
        for(int i=0;i<S.Length;i++)
        {
            if(S[i]==C)
            {
                temp.Add(i);
            }
        }

        for(int i=0;i<S.Length;i++)
        {
            if(i<temp[0])
            {
                result[i]=temp[0]-i;
            }
            else if(i>temp[temp.Count-1])
            {
                 result[i]=i-temp[temp.Count-1];
            }
            else
            {
                int current=Math.Abs(i-temp[0]);
                for(int j=1;j<temp.Count;j++)
                {
                    int ct=Math.Abs(i-temp[j]);
                    if(ct<current)
                    {
                        current=ct;
                    }
                }
                result[i]=current;
            }
        }
        
        return result;
    }
}
```