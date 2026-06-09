这种回溯的题用python的reduce x lambda做法真的太pythonic了。而且速度非常快~

```python
class Solution:
    def letterCombinations(self, digits):
        if '' == digits: return []
         
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])
```



`reduce(function, sequence [, initial] ) -> value`
lambda里,acc digit是形参，[x + y for x in acc for y in kvmaps[digit]]是函数表达式，后面的digits, ['']是实参
这里['']是初始值，先参与运算。所以第一次运算的acc是[''],digit是digits[0]，所以相当于把['']和'abc'互相拼接

第二次运算把上次lambda运算结果作为acc，digits[1]作为digit，所以是'abc'
一个小例子，说明计算'234'的过程
```
[x + y for x in [''] for y in 'abc'] 
#['a', 'b', 'c']
[x + y for x in ['a', 'b', 'c'] for y in 'def'] 
#['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
[x + y for x in ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf' ] for y in 'ghi']
#太多了写不下，应该是27个
```

