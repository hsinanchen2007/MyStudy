```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        number = ['0'] * n

        def increment(number):
            length = len(number)
            is_overflow = False
            n_takeover = 0
            for i in range(length-1, -1, -1):
                sum_ = ord(number[i]) - ord('0') + n_takeover
                if i == length - 1:
                    sum_ += 1
                if sum_ >= 10:
                    if i == 0:
                        is_overflow = True
                    else:
                        sum_ -= 10
                        n_takeover = 1
                        number[i] = str(sum_)
                
                else:
                    number[i] = str(sum_)
                    break
            return is_overflow

        ans = []
        while not increment(number):
            i = 0
            while number[i] == '0':
                i += 1
            ans.append(int(''.join(number[i:])))
            
        return ans

    def printNumbers1(self, n: int) -> List[int]:
        ans = []

        def recur(s, m):
            if m == n:
                ans.append(int(s))
                return
            for i in range(10):
                recur(s+str(i), m+1)
        
        recur('', 0)

        return ans[1:]
```