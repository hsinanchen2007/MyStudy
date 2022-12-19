### 解题思路
父状态只影响一个字符

### 代码

```csharp
using VT = System.ValueTuple<char, int>;
class CountStr
{
    private const UInt64 ModV = 1000000000 + 7;
    private Dictionary<VT, UInt64> cache = new Dictionary<VT, ulong>();
    public int total = 0;
    private UInt64 CN(char start, int leftLen)
    {
        total++;
        if (leftLen <= 0) return 1;
        var k = (start, leftLen);
        if (cache.ContainsKey(k)) return cache[k];
        if (start == '\0')
        {
            var n1 = CN('a', leftLen - 1);
            var n2 = CN('e', leftLen - 1);
            var n3 = CN('i', leftLen - 1);
            var n4 = CN('o', leftLen - 1);
            var n5 = CN('u', leftLen - 1);
            var total = n1 + n2 + n3 + n4 + n5;
            total %= ModV;
            cache.Add(k, total);
            return total;
        }
        if (start == 'a')
        {
            var total = CN('e', leftLen - 1);
            cache.Add(k, total);
            return total;
        }
        if (start == 'e')
        {
            var n1 = CN('a', leftLen - 1);
            var n2 = CN('i', leftLen - 1);
            var total = n1 + n2;
            total %= ModV;
            cache.Add(k, total);
            return total;
        }
        if (start == 'i')
        {
            var n1 = CN('a', leftLen - 1);
            var n2 = CN('e', leftLen - 1);
            var n3 = CN('o', leftLen - 1);
            var n4 = CN('u', leftLen - 1);
            var total = n1 + n2 + n3 + n4;
            total %= ModV;
            cache.Add(k, total);
            return total;
        }
        if (start == 'o')
        {
            var n1 = CN('i', leftLen - 1);
            var n2 = CN('u', leftLen - 1);
            var total = n1 + n2;
            total %= ModV;
            cache.Add(k, total);
            return total;
        }
        if (start == 'u')
        {
            var n1 = CN('a', leftLen - 1);
            cache.Add(k, n1);
            return n1;
        }
        return 0;
    }
    public int CountVowelPermutation(int n)
    {
        return (int)CN('\0', n);
    }

    // static void Main(string[] arg)
    // {
    //     {
    //         var cs = new CountStr();
    //         var r = cs.CountVowelPermutation(5);
    //         Console.WriteLine(r + ":" + cs.total);
    //     }
    // }
}
public class Solution {
    public int CountVowelPermutation(int n) {
        var cs = new CountStr();
        return cs.CountVowelPermutation(n);
    }
}
```