### 解题思路
方法1：二进制转换

### 代码

```csharp
public class Solution {
    public int HammingWeight(uint n) {        
        string s = Convert.ToString(n,2);
        return s.Count(x => x == '1');
    }
}
```