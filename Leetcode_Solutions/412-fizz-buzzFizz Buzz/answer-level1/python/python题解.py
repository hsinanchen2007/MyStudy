```
class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        for temp in range(1,n+1):
            if temp % 3 == 0 and temp % 5 == 0:
                result.append( 'FizzBuzz')
            elif temp % 3 == 0:
                result.append('Fizz')
            elif temp % 5 == 0:
                result.append('Buzz')
            else:
                result.append(str(temp))
        return result
```
