```
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        li = list(range(1,n+1))
        for i in range(len(li)):
            if (i+1) % 3 == 0 and (i+1) % 5 !=0:
                li[i] = 'Fizz'
            elif (i+1) % 5 == 0 and (i+1) % 3 != 0:
                li[i] = 'Buzz'
            elif (i+1) % 3 == 0 and (i+1) % 5 == 0:
                li[i] = 'FizzBuzz'
            else:
                li[i] = str(i+1)
        return li 
        
```
