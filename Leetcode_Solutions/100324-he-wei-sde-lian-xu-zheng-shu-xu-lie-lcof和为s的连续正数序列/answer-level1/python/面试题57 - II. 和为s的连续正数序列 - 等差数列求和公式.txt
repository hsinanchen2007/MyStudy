### 解题思路
执行用时 :120 ms, 在所有 Python 提交中击败了39.29%的用户
内存消耗 :13 MB, 在所有 Python 提交中击败了100.00%的用户
通过等差数列公式可以得到项数n=(1 - 2 * i + sqrt((2 * i - 1) ** 2 + target * 8)) / 2
i为数列首项值
因为数列至少有2项，所以只需遍历target的前半部分，从1开始依次赋值给i然后代入上面公式求出n
如果n为整数则表示当前的i为数列首项，n为数列项数，从而可以生成数列对应的数组

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        from math import floor, sqrt
        rt = []
        for i in range(1, int(floor(target / 2)) + 1):
            n = (1 - 2 * i + sqrt((2 * i - 1) ** 2 + target * 8)) / 2
            if n % 1 == 0:
                rt.append([i + x for x in range(int(n))])
        return rt
```