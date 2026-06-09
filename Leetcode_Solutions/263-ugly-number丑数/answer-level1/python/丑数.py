### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:  ## 如果num非正，就不是丑数
            return False
        while True:
            last = num
            if not num % 2:  ## 如果2整除num，就除以2
                num >>= 1
            if not num % 3:  ## 如果3整除num，就除以3
                num //= 3
            if not num % 5:  ## 如果5整除num，就除以5
                num //= 5
            if num == 1:  ## 如果若干次操作后，num变成1，说明num的因数只有2、3、5，是丑数
                return True
            if last == num:  ## 如果1轮操作后，num没变，说明num不是丑数
                return False

# 作者：erik_chen

        # 为啥自己这样写就不能通过用例数字1呢？
        # if num <= 0:
        #     return False
        # while 1:
        #     rest = num
        #     if num % 2 != 0:
        #         num //= 2
        #     if num % 5 != 0:
        #         num //= 5
        #     if num % 3 != 0:
        #         num //= 3 
        #     if rest == num:
        #         return False
        #     if num == 1:
        #         return True
            
            

```