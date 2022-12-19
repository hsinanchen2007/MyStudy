### 解题思路
没啥思路，直接求出平方放组里，然后懒的写排序了  直接用微软自带的排一下

### 代码

```csharp
public class Solution {
    public int[] SortedSquares(int[] A) {
        List<int> b = new List<int>();
        for (int i = 0; i < A.Length; i++)
        {
            b.Add(Math.Pow(A[i],2));
        }
        b.Sort();
        return b.ToArray();
    }
}
```