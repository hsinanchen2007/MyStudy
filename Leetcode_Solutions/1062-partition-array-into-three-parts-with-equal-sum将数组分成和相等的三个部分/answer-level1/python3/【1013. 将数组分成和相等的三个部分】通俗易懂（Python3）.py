## 思路

我们要将数组平均分成三分，那么每一份的和一定是sum(A)/3。因此我们的思路就是：

- 从左往右遍历，遍历的同时累加，当加到 sum(A)/3，我们cnt + 1。累加器归零
- 最后我们只要检查 cnt 大于等于 3。
> 大于是为了处理和为 0 的情况

## 代码

```python
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3 != 0: return False
        cur = cnt = 0
        for a in A:
            cur += a
            if cur == total // 3:
                cnt += 1
                cur = 0
        return cnt >= 3
```

感谢@求2020暑期实习TT 的提醒， 实际上我们cnt 到达2，就没必要检查了，最后的一段一定也是满足的。代码如下：

```python
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3 != 0: return False
        cur = cnt = 0
        for a in A:
            cur += a
            # 这里可以提早退出
            if cnt == 2: return True
            if cur == total // 3:
                cnt += 1
                cur = 0
        return False
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
