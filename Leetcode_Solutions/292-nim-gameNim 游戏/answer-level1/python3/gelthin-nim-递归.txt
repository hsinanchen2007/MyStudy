### 解题思路
这题就是xuebo 和 yuyang laoshi 的面试题。

看官方题解: 要想赢，得总是给第二个人留 4 个石头。

一个优秀的题解 [从递归到dp，然后推导出结论](https://leetcode-cn.com/problems/nim-game/solution/cong-dptui-dao-chu-jie-lun-by-aristotle-2/)

第一个人先拿 n%4 个，然后不管第二个人拿 k 个，第一个人都拿 4-k 个，永远凑 4 个一组。
前提是 n%4 == 0

评论说取模、除法都很慢，尽量用位运算，加减，乘法，
本题可以返回  n&3

如果没有想到此，可以用 DP 求解。因为 第一个人可以拿 1,2,3。重叠子问题，最优子结构，有向无环图，都可以递归，然后 DP 求解。
DP[i] = ! DP[i-1] or ! DP[i-2] or ! DP[i-3] 

DP[i] 表示两个人来拿 i 个石头，是否最后一部分石头是首先拿的人拿的。

第一个人先拿 1 个，接下来是第二个人先手，如果第二个人必输，也即 DP[i-1]为 False, 那么就相当于第一个人赢了。




### 代码

```python3
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n%4 != 0
```

