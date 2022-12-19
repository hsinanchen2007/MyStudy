### 解题思路
C# 使用等差数列求和公式计算

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
        List<int[]> result = new List<int[]>();
        // i 表示尝试使用几个数字拼凑结果，使用 i 递减循环，使元素数量更多即元素数据更小的方案出现在前面
        for (int i = target / 2 + 1; i >= 2; i--)
        {
            // 计算每个组成数字与基数的差值的和
            var diffSum = i * (i + 1) / 2;
            // 计算每个数字里基数的和
            var baseSum = target - diffSum;
            // 过滤掉基数不合法的方案
            if (baseSum < 0 ||
                baseSum % i != 0)
            {
                continue;
            }
            // 计算基数
            var baseValue = (target - diffSum) / i;
            // 使用基数拼凑出正确方案
            result.Add(Enumerable.Range(1, i).Select(index => baseValue + index).ToArray());
        }
        return result.ToArray();
    }
}
```