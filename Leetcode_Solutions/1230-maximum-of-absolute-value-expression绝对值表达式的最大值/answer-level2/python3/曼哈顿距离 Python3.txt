### 解题思路：

我们将 `arr1` 中的所有值看做平面上点的横坐标，将` arr2` 中的所有值看做平面上点的纵坐标，那么表达式 `|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|`，前两项就可以看成是平面上两点的曼哈顿距离，整个式子就是要求两个点的曼哈顿距离与两个点索引差的和。

由于有取绝对值的操作存在，那么可能产生的计算有 $4$ 种，分别为：右上减左下，右下减左上，左上减右下，左下减右上。以测试样例为例，第一组样例如左图，右上减左下取得最大值为 `3 + 7 + 3 = 13`；第二组样例如右图，右下减左上取得最大值为 `15 + 3 + 2 = 20`。

![图解](https://pic.leetcode-cn.com/0694374c9757f3116891baeb0a3adb0f0894c2b5ad7fe3aaa14e9f96a03c060d.png){:width=600}
{:align=center}

所以我们枚举 $4$ 种情况，分别求出每种情况中的最大值和最小值，然后做差更新答案即可。

### 代码：
```python [-Python]
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        n = len(arr1)
        ans = 0
        # 枚举四个方向
        for dx, dy in [(1, 1), (-1, 1), (1, -1), (-1, -1)]:
            maxv = 0
            minv = 4000000
            # 计算当前方向上的曼哈顿距离最小值和最大值
            for i in range(n):
                maxv = max(maxv, arr1[i] * dx + arr2[i] * dy + i)
                minv = min(minv, arr1[i] * dx + arr2[i] * dy + i)
            # 更新答案
            ans = max(ans, maxv - minv)
        return ans
```