`python candidate restore solution to avoid String manipulation 100% in mem cost.`

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        candidate = -1

        def helper(num, head, tail, decimal):
            nonlocal candidate
            if num == 0: return 

            div, res = num//10, num%10
            if res == 6:
                candidate = (div * 10 + 9)*10**decimal + tail
            
            helper(div, head, res*10**decimal + tail, decimal + 1)

        helper(num, 0, 0, 0)

        return candidate if candidate > 0 else num

```