### 解题思路
一直除取余数，再把余数减去就行，当0.099999*k(k是10，100，1000递增)>x的时候停止
### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        #不用字符串
        if x < 0:
            return False
        else:
            array = []
            k = 10
            while True:
                digit = x%k
                x = x-digit
                array.append(digit//(k//10))
                k = k*10
                if 0.099999999999*k > x:
                    break
            return array==array[::-1]


```