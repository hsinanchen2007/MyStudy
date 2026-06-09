```
class Solution:
    def fizzBuzz(self, n: int):
        res = [str(i) for i in range(1,n+1)]
        if n >= 3:
            res[2::3] = ['Fizz']*len(res[2::3])
        if n >= 5:
            res[4::5] = ['Buzz']*len(res[4::5])
        if n >= 15:
            res[14::15] = ['FizzBuzz']*len(res[14::15])

        return res
```

