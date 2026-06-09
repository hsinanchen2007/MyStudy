### 解题思路
位运算

### 代码

```csharp
public class Solution {
    public int HammingWeight(uint n) {
        int count=0;
        while(n > 0)
        {
            // 右移一位，判断最后一位
            // 无法处理带签名的整数
            if((n & 1) == 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
}
```