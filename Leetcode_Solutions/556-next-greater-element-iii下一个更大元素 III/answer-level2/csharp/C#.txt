首先，返回的数字比原数 **大** 且 **位数相同** ，这就需要在低位处找到一个比高位处大的数字并 **交换**

低位在右高位在左，从右至左遍历保证得到的数尽可能小

一旦发生了高低位数的 **交换** 就说明有解，但这个解不一定最小，所以把交换的高位右边的数字升序排列

`s.Append(s.ToString(i + 1, len - i - 1).OrderBy(a => a).ToArray()).Remove(i + 1, len - i - 1);`

最后进行 StackOverFlow 的检查

`if (len >= 10 && int.Parse(s.ToString(0, len - 1)) > int.MaxValue / 10)
                        return -1;`

```csharp []
public class Solution {
    public int NextGreaterElement (int n)
    {
        StringBuilder s = new StringBuilder(n.ToString());
        int len = s.Length;
        for (int i = len - 2; i >= 0; i--)
        {
            for (int m = len - 1; m > i; m--)
            {
                if (s[m] > s[i])
                {
                    char c = s[m];
                    s[m] = s[i];
                    s[i] = c;
                    s.Append(s.ToString(i + 1, len - i - 1).OrderBy(a => a).ToArray()).Remove(i + 1, len - i - 1);
                    if (len >= 10 && int.Parse(s.ToString(0, len - 1)) > int.MaxValue / 10)
                        return -1;
                    return int.Parse(s.ToString());
                }
            }
        }
        return -1;
    }
}
```

