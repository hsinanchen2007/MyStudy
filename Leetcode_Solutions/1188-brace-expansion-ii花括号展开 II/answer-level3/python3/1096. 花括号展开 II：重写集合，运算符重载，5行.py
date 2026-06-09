![image.png](https://pic.leetcode-cn.com/7e70778a1896e96ad9be5c2041e724823a192c3348994b97de14932187bbc4ae-image.png)

建立一个set集合类的子类，重写`+`运算和`*`运算，其中加运算取并集，乘运算取笛卡尔积。

然后处理表达式为指定格式的表达式，最后`eval`执行后排序即可得出答案。

```python []
class S(set):
    def __add__(self, other):
        return S(self | other)
    
    def __mul__(self, other):
        return S(i + j for i, j in itertools.product(self, other))
    
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        expression = re.sub('(\w+)', r'S(["\1"])', expression)
        d = {',': '+', '{': '(', '}': ')'}
        expression = re.sub('[\,\{\}]', lambda x: d[x.group(0)], expression)
        expression = re.sub('\)([S\(])', r')*\1', expression)
        return sorted(S(eval(expression)))
```

或者这样写也行：

```python []
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        class S(set):
            __add__ = lambda s, o: S(s | o)
            __mul__ = lambda s, o: S(i + j for i, j in itertools.product(s, o))
        expression = re.sub('(\w+)', r'S(["\1"])', expression).replace(',', '+').replace('{', '(').replace('}', ')').replace(')(',')*(').replace(')S',')*S')
        return sorted(S(eval(expression)))
```
