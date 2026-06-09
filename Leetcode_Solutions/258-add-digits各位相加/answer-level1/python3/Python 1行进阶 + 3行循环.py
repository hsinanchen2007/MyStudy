```python
class Solution:
    def addDigits(self, num: int) -> int:
        return num % 9 or 9 * bool(num)
```
- O(1) 数学推理：设某个数字的字符串表示为`'abc'`，则这个数字代表`a*100 + b*10 + c`，转换后成为`a + b + c`，可见每次转换相当于把原数字减去`a*99 + b*9 = 9 * (a*11 + b)`，可以推出只要高于个位的位置上有数字，算法就会减去一个小于原数字的9的倍数，这就相当于`数字 % 9`。但`9 % 9 = 0`，而 9 本身就没有十位，因此需要考虑原数字是 0 或 9 的倍数的特殊情况
- 首先计算`num % 9`，若结果为 0 则考虑`num`本身是否为 0，若不为 0 返回 9
```python
class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            num = eval('+'.join(n for n in str(num)))
        return num
```
- 循环判断