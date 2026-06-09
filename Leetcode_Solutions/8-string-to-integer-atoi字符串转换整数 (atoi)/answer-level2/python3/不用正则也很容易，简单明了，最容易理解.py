不用正则表达式，思维比较清晰如下
（1)符号可有可无，一旦有必须在数字前面
（2)前置空格，跟符号一样，因此可以一同处理，区别就是前置空格不计入
（3)数字判断，通过上1，2判断完毕，只要不是数字就结束
但是有个问题，就是结果为'+','','-'的情况需要判断下，就返回0，否则判断是否溢出
```python[]
class Solution():
    def myAtoi(self, s: str) -> int:
        if not s:
            # 不多BB，空串爬开
            return 0
        temp = ''
        sign = {' ', '+', '-'}
        for i in s:
            if i in sign:
                # 如果符号之前有temp有内容，则结束循环
                if temp:
                    break
                # temp无内容，前置空格不计入
                if i != ' ':
                    temp += i
            elif '0' <= i <= '9':
                # i为数字，计入
                temp += i
            else:
                # 通过上测试，其余直接pass('++','a1','-1+0'等情况)
                break
        if not temp or temp in sign:
            # temp空或只含有+-符号，直接返回0
            return 0
        # 简单溢出处理
        return max(min(int(temp), 2147483647), -2147483648)
```
哈哈哈，第一次发，扣题，不断优化
不是很快：最好40ms，哈哈哈

