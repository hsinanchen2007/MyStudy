### 解题思路
1.正整数序列，假设连续i个正整数
2.i是偶数，则target/i必须结果=1.5,2.5,3.5....总而言之，余数应该是i/2。即最终的序列以target/i为中心对称（但不属于序列），两边各有i/2个数。
3.i是奇数，则target/i必须结果=整数，即最终的序列以target/i为中心，两边各有(i-1)/2个数。
4.正整数序列，因此中间数左侧应该有足够的长度空间。用于尽早break。
5.序列越长，序列的头部越小。所以，最后逆序。

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
            var res = new List<int[]>();

            for(var i = 2; i < target; i++)
            {
                if ((i % 2 == 1 && i / 2 >= target / i) || (i % 2 == 0 && i / 2 > target / i))
                    break;
                if (i % 2 == 0 && target % i == i / 2) //i偶数 & target/i=m+0.5
                {
                    var oneres = new int[i];
                    var left = target / i - i / 2 + 1;
                    for (var index = 0; index < i; index++)
                        oneres[index] = left + index;
                    res.Add(oneres);
                }
                else if (i % 2 == 1 && target % i == 0) //i奇数 & target/i整除
                {
                    var oneres = new int[i];
                    var left = target / i - i / 2;
                    for (var index = 0; index < i; index++)
                        oneres[index] = left + index;
                    res.Add(oneres);
                }
            }
            res.Reverse();
            return res.ToArray();
    }
}
```