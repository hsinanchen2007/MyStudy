笨办法，速度好像还可以的样子
```python []
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        str_ = ["0"] * n
        for i in range(0,n,1):
            if (i + 1) % 3 == 0 and (i + 1) % 5 == 0:
                str_[i] = "FizzBuzz"
            elif (i + 1) % 3 == 0 and (i + 1) % 5 != 0:
                str_[i] = "Fizz"
            elif (i + 1) % 3 != 0 and (i + 1) % 5 == 0:
                str_[i] = "Buzz"
            elif (i + 1) % 3 != 0 and (i + 1) % 5 != 0:
                str_[i] = str(i + 1)
        return str_
```
