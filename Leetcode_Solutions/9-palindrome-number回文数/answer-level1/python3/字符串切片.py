### 解题思路
利用切片 取出左边和翻转后的右边，如果两个结果相同，返回 true
负数一定不是回文数

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # numbers less than 0 are definitely not the palindromes
        if x < 0 :
            return False
        else:
            # get left and right
            #  result = reverse(right)
            # if left == result  true
            string = str(x)
            lenth = len(string)
            if lenth % 2 == 0:
                mid = int(lenth / 2)
            elif lenth % 2 == 1:
                mid = int((lenth - 1) / 2)
            # left = string[:mid]
            # right = string[:-(mid+1):-1]
            # if left == right:
            #     return True
            if string[:mid] == string[:-(mid+1):-1]:
                return True
            else:
                return False

            
```