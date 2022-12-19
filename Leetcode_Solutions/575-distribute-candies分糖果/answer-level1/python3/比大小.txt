# 成绩（2019.05.09）
执行用时 : 148 ms, 在Distribute Candies的Python3提交中击败了91.24% 的用户

内存消耗 : 14.5 MB, 在Distribute Candies的Python3提交中击败了92.54% 的用户

# 思路

给哥哥妹妹糖是顺序任意的。

如果糖的种类大于等于糖的个数的一半，那么妹妹最多获得糖的个数的一半的种类的糖。

如果种类数少于个数的一半，那么最多获得种类数的糖


```python
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        can = set(candies)
        if len(can) <= len(candies)//2:
            return len(can)
        else:
            return len(candies)//2
```