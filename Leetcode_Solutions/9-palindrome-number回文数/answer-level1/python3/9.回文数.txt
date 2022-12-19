### 解题思路
循环：
    余数等到最后一位
    反转数：乘十加余数
判断反转数和x是否相等返回结果
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 :
            return False
        
        m,n = x,0
        
        while m:
            n = n*10 + m%10
            m = m//10
            
        if x == n:
            return True
        else:
            return False



```