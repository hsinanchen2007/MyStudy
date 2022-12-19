### 解题思路
执行用时 :52 ms, 在所有 Python 提交中击败了97.64%的用户
内存消耗 :16.9 MB, 在所有 Python 提交中击败了100.00%的用户
1.计算出数组和的1/3
2.遍历并累加数组
3.累加和等于数组和1/3时计数
4.当得到第二个计数时返回true

### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if not A or sum(A) % 3 > 0:
            return False
        s = sum(A) / 3
        bin = 0
        cnt = 0
        for i in A:
            if cnt == 2:
                return True
            bin += i
            if bin == s:
                bin = 0
                cnt += 1
        return False   
```