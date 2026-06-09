```python
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        # rerange to divide 3
        # all number sum % 3 == 0
        # digits.length <= 10 ** 4
        # a + b + c 
        # Greedy
        # Time complexity : O(N)
        # Space complexity: O(N)
        mod0, mod1, mod2 = [], [], []
        for digit in digits:
            if digit % 3 == 0:
                mod0.append(digit)
            elif digit % 3 == 1:
                mod1.append(digit)
            else:
                mod2.append(digit)
                
        res = mod0
        mod2.sort()
        mod1.sort()
        def putElement(arr):
            if arr: res.append(arr.pop())
        def processRest(arr):
            while len(arr) >= 3:
                for _ in range(3):
                    res.append(arr.pop())
        
        while mod2 and mod1:
            if len(mod1) > 3 and len(mod2) > 3:
                res.append(mod1.pop())
                res.append(mod2.pop())
            elif len(mod2) == 1:
                if len(mod1) >= 3:
                    processRest(mod1)
                    continue
            elif len(mod1) == 1:
                if len(mod2) >= 3:
                    processRest(mod2)
                    continue
    
            putElement(mod1)
            putElement(mod2)
                
        processRest(mod1)
        processRest(mod2)

                               
        if res == []: return ''
        res.sort(reverse = True)
        res = ''.join(map(str, res)).lstrip('0')
        return '0' if res == '' else res
```