### 解题思路
很鸡贼的用了内置的函数。

### 代码

```csharp
public class Solution {
    public int SumNums(int n) {
        return  Enumerable.Range(0,n+1).Aggregate((x,y)=>x+y);
    }
}
```