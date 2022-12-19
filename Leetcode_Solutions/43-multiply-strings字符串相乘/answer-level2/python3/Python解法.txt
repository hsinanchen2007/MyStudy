### 解题思路

注意到

两数相乘的结果，长度不会超过两数的长度之和

我们就可以用数组存结果

然后 数字1的i位和数字j位的数，会更新乘积的i+j+1位(肯定会更新)，i+j位（如果溢出就会更新），i+j+1位（溢出更新）

但是i+j+1位可以先不考虑，因为我们数组中i+j位的数可以大于10，这个会被其他的和延迟更新

### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len_one = len(num1)
        len_two = len(num2)
        list = [0]*(len_one+len_two)

        for i in range(1,len_one+1):
            num1Val = int(num1[-i]);
            for j in range(1,len_two+1):
                num2Val = int(num2[-j])
                sum = list[-(i + j - 1)] + num1Val * num2Val
                list[-(i + j - 1)] = sum % 10 
                list[-(i + j)] += sum // 10


        result = ""
        start = len_one+len_two-1
        for i in range(len_one+len_two):
            if list[i] != 0:
                start = i
                break
        
        for i in range(start,len_one+len_two):
            result += str(list[i])

        return result
```