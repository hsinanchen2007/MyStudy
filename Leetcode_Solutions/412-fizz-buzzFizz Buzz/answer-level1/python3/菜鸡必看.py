```
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res=[]
        for i in range(1,n+1) :
            res.append(str(i))
#这里不能+= 比如10的话会切割成"1","0"
        for j in range(3,n+1,3):
            res[j-1]="Fizz"
        for j in range(5,n+1,5):
            res[j-1]="Buzz"
        for j in range(15,n+1,15):
            res[j-1]="FizzBuzz"
        return res
```
