如果把一个例子写成算式，会发现其实是用加号和减号把石头门的重量连起来，并使结果最小：
例子[2,7,4,1,8,1]中：
“组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
”
即
1-（（4-2）-（8-7））
也就是
1+2+8-4-7


换一种想法，就是 将这些数字分成两拨，使得他们的和的差最小

在进一步，可以变成 选出一些数字，使得它们最逼近整个数组和除以二的值，而最后的结果，就是abs（这个数-总和除以二）*2


那么现在，就可以写代码了：

```python []
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        target = sum(stones)/2.0
        candidates = {0}
        for x in stones:
            addition = set()
            for y in candidates:
                if x+y<= target:
                    addition.add(x+y)
            candidates = candidates.union(addition)
        return int(2*(target-max(candidates)))
```

执行用时 :52 ms, 在所有 Python3 提交中击败了97.78%的用户 内存消耗 :13.9 MB, 在所有 Python3 提交中击败了100.00%的用户

再优化一下：


```python []
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        target = sum(stones)/2.0
        candidates = {0}
        for x in stones:
            addition = set()
            for y in candidates:
                s = x+y
                if s==target:
                    return 0
                elif x+y< target:
                    addition.add(s)
            candidates = candidates.union(addition)
        return int(2*(target-max(candidates)))
```

执行用时 :48 ms, 在所有 Python3 提交中击败了100.00%的用户内存消耗 :14 MB, 在所有 Python3 提交中击败了100.00%的用户
