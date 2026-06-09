### 解题思路
清晰明了 简单不少 把转成的2进制 存下来 然后按位对比  一个number / 2 的余数 直到number / 2 = 0 为止 把所有余数连起来就是对应的二进制数值 比如 13/2 = 6 余 (1), 6/2 = 3 余 (0),3/2 = 1 余 (1)，1/2=0 余 (1) 二进制就是 1101

### 代码

```csharp
public class Solution {
    Stack<int> s1, s2;
    public int HammingDistance(int x, int y) {
        s1 = new Stack<int>();
        s2 = new Stack<int>();

        while(x > 0)
        {
            s1.Push((x & 1) == 0 ? 0 : 1);
            x /= 2;
        }

        while(y > 0)
        {
            s2.Push((y & 1) == 0 ? 0 : 1);
            y /= 2;
        }
        int sum = 0;
        while(s1.Count != s2.Count )
        {
            if((s1.Count > s2.Count ? s1 : s2).Pop() == 1) sum++;
        }
        while(s1.Count != 0 || s2.Count != 0)
        {
            if((s1.Count == 0 ? 0 : s1.Pop()) != (s2.Count == 0 ? 0 : s2.Pop())) sum++;
        }
        return sum;
    }
}
```