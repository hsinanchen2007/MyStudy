### 解题思路
纯数学

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