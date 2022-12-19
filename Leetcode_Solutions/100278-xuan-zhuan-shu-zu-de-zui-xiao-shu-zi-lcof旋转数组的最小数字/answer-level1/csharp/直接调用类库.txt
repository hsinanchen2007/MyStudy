### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MinArray(int[] numbers) {
        Array.Sort(numbers);
        return numbers[0];
    }
}
```