```
class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = [''] * n

        for i in range(1, n//3+1):
            result[i*3-1] += 'Fizz'
        for i in range(1, n//5+1):
            result[i*5-1] += 'Buzz'
        
        for i in range(len(result)):
            if result[i] == '':
                result[i] = str(i+1)

        return result
```
