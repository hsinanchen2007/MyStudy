# 枚举方式
将“（”视为1，“）”视为0，则每一个括号组合可以视为一个二进制数。因此，可以使用整数来枚举所有组合。
n=3, 其合理组合对应的值域为[101010b, 111000b]，即[42, 56], 暴力破解枚举的范围包含此值域即可。
```
min = Enumerable.Range(0, n).Aggregate(0, (acc, i) => acc |= 1 << (2 * i + 1))
max =  (1 << 2 * n) - (1 << n) 
```

# 判断组合是否有效
通过聚合函数，将数值二进制位从右向左（低位到高位）逐个累计0、1两者数量差值，0“）”则加1， 1 “（” 则减1，如果出现负值则组合无效，保留负值不再继续累计。最后，如果累计的值为0则表示组合有效。

```
Enumerable.Range(0, 2 * n)
  .Aggregate(0, (last, i) => last < 0 ? last : last + ((num >> i & 1) == 0 ? 1 : -1)
    , value => value == 0)
```

# C# Code

```
public class Solution {
    public IList<string> GenerateParenthesis(int n)
    {
          return Enumerable.Range(Enumerable.Range(0, n).Aggregate(0, (acc, i) => acc |= 1 << (2 * i + 1)), 
                    n == 0 ? 0 : (1 << 2 * n) - (1 << n) - Enumerable.Range(0, n).Aggregate(0, (acc, i) => acc |= 1 << (2 * i + 1)) + 1)
                .Where(num => Enumerable.Range(0, 2 * n).Aggregate(0, (last, i) => last < 0 ? last : last + ((num >> i & 1) == 0 ? 1 : -1), value => value == 0))
                .Select(num => Convert.ToString(num, 2).Replace('1', '(').Replace('0', ')')).ToList();

    }
}
```

# JAVA Code
```
class Solution {
    public List<String> generateParenthesis(int n) {
        return IntStream.rangeClosed(IntStream.range(0, n).reduce(0, (acc, i) -> acc |= 1 << (2 * i + 1)), n == 0 ? -1 : (1 << 2 * n) - (1 << n))
                .filter(num -> IntStream.range(0, 2 * n).reduce(0, (last, i) -> last < 0 ? last : last + ((num >> i & 1) == 0 ? 1 : -1)) == 0)
                .mapToObj(num -> Integer.toBinaryString(num).replace('1', '(').replace('0', ')'))
                .collect(Collectors.toList());
    }
}
```