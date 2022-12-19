### 解题思路
利用c#自带函数将n转换成2进制字符串，然后计算字符串中1的个数。

### 代码

```csharp
public class Solution {
    public int HammingWeight(uint n) {
        string s = Convert.ToString(n,2);
        return s.Count(x => x == '1');
    }
}
```