### 解题思路
判断是否为负数，如果是直接就不是回文数
将数直接进行反转，后比较

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        number=x
        temp=0
        while(number!=0):
            temp=temp*10+number%10
            number//=10
        print(temp)
        if temp==x:
            return True
        return False
```