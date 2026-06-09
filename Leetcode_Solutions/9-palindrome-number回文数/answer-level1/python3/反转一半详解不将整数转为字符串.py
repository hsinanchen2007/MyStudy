### 解题思路
取后一半数值和前一半对比。如果相同则为回文数。


### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0): #x小于0负数不是回文数，x%10等于0，整数不可以用0开头
            return False                      # 0~9都是回文数
        reversal = 0                          #这是反转好的结果
        while(x>reversal):                    #如果反转的数字大于当前剩余的数字就到一半了
            reversal = reversal*10 + x % 10   #新取出来的数字要加在后面
            x = x//10                         #旧的数字要把尾巴删掉
        return x == reversal or x == reversal//10 #为什么有两个判断条件因为有的数字正中间是个数
```