### 解题思路
这一题同[492. 构造矩形题](https://leetcode-cn.com/problems/construct-the-rectangle/)

想要进一步加速，但没有写出更好的代码。
``` python3

### 进行素数因子分解
factor = dict()
x = 2
while x<num:
if num%x == 0:
factor[x] = 0
while num%x == 0:
factor[x] += 1
num = num//x
x += 1
 
### 回溯法生成所有的可能的因子 不重复。 想法很好，但写不出来。后面一定要写出来
result = []
val = 1
for x, y in factor.items():
    for i in range(y):
        val *= x**i

```

### 代码

```python3
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        ## 首先查找平方根
        left, right = 0, num//2+1
        while left<right:
            mid = left + (right-left+1)//2
            if mid*mid > num:
                right = mid-1   # 小于等于 sqrt(sum) 的最大整数
            else:
                left = mid
        
        res = 1
        for x in range(2, left+1):  # 这里细节很重要啊， left 可以取，不然那样例 6  left=2, 过不了
            if num%x == 0:
                res  = res + x + num//x
        if left*left == num:
            res += left
        return res==num

```