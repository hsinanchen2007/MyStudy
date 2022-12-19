**思路：**

把每个多米诺骨牌翻成小的数字在上，大的数字在下的情况，这样可以使相同的多米诺骨牌的状态也相同，便于统计数目。然后用哈希字典来统计每种多米诺骨牌的个数，最后遍历每种骨牌，用组合数学 `n * (n - 1) // 2` 求每种骨牌成对的数目，将其累加得到最后结果。

**图解：**

![图解](https://pic.leetcode-cn.com/1f1ca880ac91c6872d596d8990e7685b3ffb5baadda4fbb62d551c3352f31596.gif){:width=500}
{:align=center}


**代码：**
```python [-Python]
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        ans = 0
        d = dict()
        for d1, d2 in dominoes:
            # 排序后加入字典
            index = tuple(sorted((d1, d2)))
            if index in d:
                d[index] += 1
            else:
                d[index] = 1
        # 计算答案
        for i in d:
            ans += d[i] * (d[i] - 1) // 2
        return ans
```