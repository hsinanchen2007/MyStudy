### 解题思路
![code.PNG](https://pic.leetcode-cn.com/26e49854700e7fd029c3fb6cfe9997952d070eed97455a4a853d3455138b241e-code.PNG)
先计算均值，再看是否能有足够的部分能够和为均值
s为划分为三个部分时的均值
a为部分的和
n为和为均值的划分部分数

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)/3
        a = 0
        n = 0
        for i in A:
            a += i
            if s == a:
                n += 1
                a = 0
        if n==3 and a==0:
            return True
        elif n<3 or a!=0:
            return False
        elif n>3 and a!=0:
            return False
        elif n>3 and a==0:
            if s==0:
                return True
            else:
                return False

```