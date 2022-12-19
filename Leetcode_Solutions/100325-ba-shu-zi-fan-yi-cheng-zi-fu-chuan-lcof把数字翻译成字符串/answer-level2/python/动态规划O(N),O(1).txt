### 解题思路
此处撰写解题思路

### 代码

```python3
#######递归
# class Solution:
#     def __init__(self):
#       self.count = 0
#     def translateNum(self, num: int) -> int:
#       def recur(Str):
#         if len(Str) <= 1:####递归终止条件
#           self.count += 1
#           return
#         else:
#           if 10 <= int(Str[:2]) <= 25:###可以拆分递归的条件
#             recur(Str[1:])
#             recur(Str[2:])
#           else:#####不可以的情况，从下一位再来
#             recur(Str[1:])
      
#       Str = str(num)
#       recur(Str)
#       return self.count
#######动态规划
"""
"12258":
f(0) = 1:空字符也算一种情况""
f(1) = 1:"1"
f(2) = f(0) + f(1):"12"->"12" + "1,2"
f(3) = f(1) + f(2):"122"->("1,22") + ("12,2","1,2,2")
f(4) = f(2) + f(3):"1225"->"1,22,5","12,2,5","1,2,2,5"
f(5) = f(4)
总结：
对于f(i),若第i位与i-1位组成的数字在（10，25）之间，则f(i) = f(i-1) + f(i-2)
否则f(i) = f(i-1)
"""

class Solution:
    def translateNum(self, num: int) -> int:
      Str = str(num)
      if len(Str) <= 1:
        return 1
      
      f0,f1 = 1,1###空字符也是1种,f0是人为设置;f1对应索引0
      for i in range(1,len(Str)):
        if 10 <= int(Str[i-1]+Str[i]) <= 25:
          f0,f1 = f1,f0 + f1
        else:
          f0,f1 = f1,f1
      return f1
      
```