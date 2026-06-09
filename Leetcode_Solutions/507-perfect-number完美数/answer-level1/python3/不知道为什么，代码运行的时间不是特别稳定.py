
```python []
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if(num <= 1):
            return False
        sum = 0
        i = 2;
        while(i*i <num):
            if(num % i == 0):
                sum += i;
                sum += num / i;
            i+=1
        if(i * i == num):
            sum += i;
        sum += 1;
        return sum == num
```