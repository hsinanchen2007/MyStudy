### 解题思路
遍历循环，有大神提供更好的思路么？

### 代码

```csharp
public class Solution {
    public int[] NumberOfLines(int[] widths, string S) {
        int line=1;
        int currentCnt=0;

        foreach(var item in S)
        {
            int temp=widths[item-'a'];
            if(temp+currentCnt>100)
            {
                currentCnt=temp;
                line++;
            }
            else
            {
                currentCnt+=temp;
            }
        }

        int[] result=new int[2];
        result[0]=line;
        result[1]=currentCnt;

        return result;
    }
}
```