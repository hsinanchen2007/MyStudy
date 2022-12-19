方法一：
```
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result=[]
        for num in range(left,right+1):
            for char in str(num): #遍历转化为字符串的num
                if char=='0' or num%int(char): #如果这一位是0，或者这一位不能整除原始值，退出循环而不执行else
                    break
            else:
                result.append(num) #如果没有break，这个数就是自除数
        return result
```
方法二：
```
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result=[]
        for num in range(left,right+1):
            original=num #保存原始值
            while num: #如果num为0，退出循环执行else
                if not(digit:=num%10) or original%digit: #如果这一位是0，或者这一位不能整除原始值，退出循环而不执行else
                    break
                num//=10 #推到下一位
            else:
                result.append(original) #如果没有break，这个数就是自除数
        return result
```
