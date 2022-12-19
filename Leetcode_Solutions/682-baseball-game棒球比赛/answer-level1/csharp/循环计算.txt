### 解题思路
循环计算每一次的值，同时持久化所有有效回合的分数，在计算完成后同时操作持久化集合。

代码其实有BUG，但是在本题限定下不影响

### 代码

```csharp
public class Solution {
    public int CalPoints(string[] ops) {
        List<int> invalidList=new List<int>();
        int result=0;
        
        for(int i=0;i<ops.Length;i++)
        {
             int temp=0;
            switch(ops[i])
            {
                case "+":
                    temp=invalidList[invalidList.Count-1]+invalidList[invalidList.Count-2];
                    invalidList.Add(temp);
                    result+=temp;
                    break;
                case "D":
                    temp=invalidList[invalidList.Count-1]*2;
                    invalidList.Add(temp);
                    result+=temp;
                    break;
                case "C":
                    temp=invalidList[invalidList.Count-1];
                    result-=temp;
                    invalidList.RemoveAt(invalidList.Count - 1);
                    break;
                default:
                    temp=Convert.ToInt32(ops[i]);
                    invalidList.Add(temp);
                    result+=temp;
                    break;
            }
        }
        return result;
    }
}
```