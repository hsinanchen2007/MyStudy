### 解题思路
用python最大的好处就是不用判断num是否溢出，简化了题的难度。
剩下的就是按照题目给的条件去实现就行了。
定义： 
symbol = ['+','-']
number = ['0','1','2','3','4','5','6','7','8','9']
如果str为空或者第一个字符不在symbol和number中，不能转换，返回0.
使用flag标记负符号位。剩余的就是常规计算。
计算完毕要判断要转化的列表transform_list是否有可以转化的元素，有可能是空。（只有一个+或者-号）
最后判断转化的整数是否溢出。
### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        symbol = ['+','-']
        number = ['0','1','2','3','4','5','6','7','8','9']
        str = str.strip()
        flag = False
        if not str or (str[0] not in symbol and str[0] not in number):
            return 0
        transform_list = []
        if str[0] in symbol:
            if str[0] == '-':
                flag = True
            str = str[1:]
        for item in str:
            if item not in number:
                break
            else:
                transform_list.append(item)
        if not transform_list:
            return 0
        else:
            num = 0
            for item in transform_list:
                num = num * 10 + int(item)
            if flag:
                num = -num
            INT_MIN = int(-pow(2, 31))
            if num < INT_MIN:
                return INT_MIN
            INT_MAX = int(pow(2,31)-1)
            if num > INT_MAX:
                return INT_MAX
            return num
```