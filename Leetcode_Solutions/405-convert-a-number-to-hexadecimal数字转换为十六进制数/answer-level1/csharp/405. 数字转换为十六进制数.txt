### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public static char[] hexChars = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

    public string ToHex(int num) {
        uint value = 0;
        if (num > 0)
        {
            value = (uint)num;
        }
        else if (num < 0)
        {
            // 使用补码算法，把负数转换为无符号整型
            // 不转换的话，负数在>>时将以1在左侧补位，导致无限循环
            value = (uint)(~-num + 1);
        }
        else
        {
            return "0";
        }

        StringBuilder builder = new StringBuilder();
        while (value != 0)
        {
            var last4Bits = value & 15;
            builder.Insert(0, hexChars[last4Bits]);
            value >>= 4;
        }
        return builder.ToString();
    }
}
```