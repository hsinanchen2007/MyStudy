### 解题思路
我的的想法是：我要怎么解决这个问题。这个题目是我从上一道简单的题目中获得的灵感。
1. 负数一定不是回文数
2. 将一个整数变为一个列表。
3. 判断列表中的第一个元素和最后一个元素是否相等

勉强算是一个解决办法吧，就是数据很差，又是一个很笨的方法

### 代码

```python3
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        x = list(map(int, str(x)))
        for i in range(len(x)) :
            if x[i] != x[len(x)-1-i] :
                return False
        return True
```