## 审题

这其实是一道著名的智商题变种，只需要倒推就可以得到正解。

利用**动态规划**的思想，从后往前规划，记录先手和后手的收益。
再利用**贪心算法**的思想，在向前迭代时，总是取三种可能性中，先手收益最大、后手收益最小的一种。
最后，判断第一手的记录，先手和后手的收益哪个大，就能得到谁获胜、或平局。

如果这也算是Hard的话，那就是难在这种思路结合吧。

## 代码技巧

中从后往前规划的过程中，有四种特殊情况。

1. 倒数第一手
2. 倒数第二手
3. 倒数第三手
4. 其它

因为，如果只剩3个石子以下，选择性就下降了。

在编码过程中，这里需要比较麻烦的处理。
但是，我找到了一种手段，可以把四种特殊情况，缩减为一种。

在`stoneValue`后面，补2个`0`，是不影响比赛结果的。
同理，在动态规划记录`dp`后面，补3个`(0, 0)`，也是不影响规划判断的。
而这样一来，原倒数第一手，就变成了倒数第三手，不存在前三种判断情况。

## 代码示例

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        length = len(stoneValue)
        stoneValue.append(0)
        stoneValue.append(0)
        dp = [None] * length
        for _ in range(3):
            dp.append((0, 0))

        for i in reversed(range(length)):
            one = stoneValue[i] + dp[i + 1][1], dp[i + 1][0]
            two = stoneValue[i] + stoneValue[i + 1] + dp[i + 2][1], dp[i + 2][0]
            three = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + dp[i + 3][1], dp[i + 3][0]
            picks = [one, two, three]
            picks.sort(key=lambda i: i[1])
            picks.sort(key=lambda i: i[0], reverse=True)
            dp[i] = picks[0]

        if dp[0][0] > dp[0][1]:
            return 'Alice'
        elif dp[0][0] < dp[0][1]:
            return 'Bob'
        else:
            return 'Tie'
```

总记24行。除了开头和空行，其实只有20行。

> 执行用时 : `3548 ms`, 在所有 Python3 提交中击败了`100.00%`的用户
> 内存消耗 : `21.3 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

当然，执行用时不太理想，因为内存上额外消耗了`O(n)`的空间复杂度。
`dp`和`stoneValue`，其实可以共用一个数组。
但那样一来，就真的需要处理四种情况了。

在竞赛过程中，只要能通过，速度越快越好。
代码量最少的方案，就是竞赛最优方案。

## 补充一个更优方案

竞赛时，有个地方搞蠢了，观赏他人题解时才反应过来。
**根本就没有必要记录后手**！
总值减去后手，就自然是先手，反之亦然。
后手收益最小，先手收益就最大。

而且，这样一来，前面为了省代码量而额外使用的`O(n)`空间，现在也可以省了。

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        dp = stoneValue
        for _ in range(3):
            dp.append(0)

        sumation = 0
        for i in reversed(range(len(dp) - 3)):
            sumation += stoneValue[i]
            dp[i] = sumation - min(
                dp[i + 1],
                dp[i + 2],
                dp[i + 3],
            )

        if dp[0] > sumation - dp[0]:
            return 'Alice'
        elif dp[0] < sumation - dp[0]:
            return 'Bob'
        return 'Tie'
```

这回是总计20行。

> 执行用时 : `668 ms`, 在所有 Python3 提交中击败了`100.00%`的用户
> 内存消耗 : `17.9 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

这大概就是Python的极限了吧。