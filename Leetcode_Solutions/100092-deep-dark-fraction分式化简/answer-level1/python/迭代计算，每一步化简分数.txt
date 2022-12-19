```
class Solution(object):
    def fraction(self, cont):
        """
        :type cont: List[int]
        :rtype: List[int]
        """
        def trans(num1, num2):
            if num1 % num2 == 0:
                return [num1 // num2, 1]
            else:
                for i in range(2, min(num1, num2)):
                    while num1 % i == 0 and num2 % i == 0:
                        num1 //= i
                        num2 //= i
                return [num1, num2]

        if len(cont) == 1:
            return [cont[0], 1]
        cont = cont[::-1]
        y = [cont[0], 1]
        for i in range(1, len(cont)):
            x = cont[i]
            y = [x * y[0] + y[1], y[0]]
            y = trans(y[0], y[1])
        return y
```