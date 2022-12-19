### 解题思路
最常规的解法，最好理解，取得上一行的数组，然后从当前索引1开始遍历到索引Length-1，计算中间节点的值，所有最左和最右的值都是1，无需计算

### 代码

```csharp
public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        List<IList<int>> result=new List<IList<int>>();
        if(numRows==0)
        {
            return result;
        }
        List<int> first=new List<int>();
        first.Add(1);
        result.Add(first);
        if(numRows==1)
        {
            return result;
        }
        List<int> second=new List<int>();
        second.Add(1);
        second.Add(1);
        result.Add(second);
        if(numRows==2)
        {
            return result;
        }
        
        for(int i=2;i<numRows;i++)
        {
            var old=result[i-1];
            List<int> current=new List<int>();
            current.Add(1);
            for(int j=1;j<i;j++)
            {
                current.Add(old[j-1]+old[j]);
            }
            current.Add(1);
            result.Add(current);
        }
        return result;

    }
}
```