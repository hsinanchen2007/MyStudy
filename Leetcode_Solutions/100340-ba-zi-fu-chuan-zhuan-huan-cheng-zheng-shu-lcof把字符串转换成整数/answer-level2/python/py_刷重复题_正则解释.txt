### 解题思路
1. findall函数找到所有满足`pattern`的东西并返回列表，
    + 由于这里开头是字母后面数字是无效的，所以`^`表示起始
    + 同时由于题目说前置空格+数字有效，所以`\s*`匹配空格0-n次
2. 符号：+-98错误(但是题目好像说一定连着)，但是正数+可有可无，因此`[+-]?`表示符号选择出现0次或1次
3. 数字：`\d+`匹配数字至少1次，且尽可能多匹配。
4. `*`:语法，可认为解包，将可迭代对象解开，传入多个参数（一般都会用在函数传参这里）
```python3
a = []
b = [1,2]
print(*a)  # 什么都没有输出=print()
print(*b)  # 相当于遍历输出,传参！

1 2
```
5. int函数：
> class int(object)
 |  int([x]) -> integer
 |  int(x, base=10) -> integer
 |  
 |  Convert a number or string to an integer, or return 0 if no arguments
 |  are given.  If x is a number, return x.__int__().  For floating point
 |  numbers, this truncates towards zero.

所以没有参数传递的`int()`返回0，刚好符合本题题意。
```python
print(int())
0
```


### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        import re
        return max(-(1 << 31), min((1 << 31) - 1, int(*re.findall('^\s*[+-]?\d+', str))))
```