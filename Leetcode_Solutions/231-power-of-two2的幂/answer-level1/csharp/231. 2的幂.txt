### 解题思路
C# 位运算，只要能保证二进制中只存在一个1即可。
n = n & (n - 1) 用于将最右边的1置为0；

### 代码

```csharp
public class Solution {
    public bool IsPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
}
```