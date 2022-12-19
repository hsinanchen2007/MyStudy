## 思路
1. 两个等长的数组，如果x为奇数个则不可能成功，因此要记录x个数。
2. 不用考虑两个数组中相等的部分，直接跳过。
3. 不相等的情况为：xx，yy 和xy，yx。第一种情况需要转化一步，第二种情况需要转化两步。
4. 可以统计下去掉两串相等位置之后x的个数，看能够组合成多少个xx，yy情况。实际上看下x和y是奇数个还是偶数个，偶数就直接除2求出转化步骤，奇数个则需要再加个2.最终就是最小转化步骤。

## 代码

```python
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        x_all_cnt = 0
        xcnt = 0
        ycnt = 0

        for i in range(len(s1)):
            if s1[i] == 'x':
                x_all_cnt += 1
            if s2[i] == 'x':
                x_all_cnt += 1
                
            if s1[i] == s2[i]:
                continue

            if s1[i] == 'x':
                xcnt += 1
            else:
                ycnt += 1

        if x_all_cnt %2 != 0:
            return -1

        res = int(xcnt/2) + int(ycnt/2)

        if xcnt %2 == 1:
            res += 2
        return int(res)
```