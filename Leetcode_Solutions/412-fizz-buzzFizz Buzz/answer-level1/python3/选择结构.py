## 思路:

选择结构

```python
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:

        res = []
        for i in range(1, n + 1):
            if i % 3 == 0 and i % 5 == 0:
                res.append("FizzBuzz")
            elif i % 3 == 0:
                res.append("Fizz")
            elif i % 5 == 0:
                res.append("Buzz")
            else:
                res.append(str(i))
                
        return res
```

一行

```python
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:

        return [
            str(i) * (i % 3 != 0 and i % 5 != 0) +
            "Fizz" * (i % 3 == 0) + 
            "Buzz" * (i % 5 == 0)
            for i in range(1, n + 1)
        ]
```

