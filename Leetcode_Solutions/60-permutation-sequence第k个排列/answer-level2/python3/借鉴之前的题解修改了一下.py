```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def backtrack(first = 0):
            if first == n:  
                output.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                backtrack(first + 1)
                nums[first], nums[i] = nums[i], nums[first]
        
        nums = list(range(1, n+1))
        output = []
        backtrack()
        output = sorted(output)
        return ''.join(list(map(str, output[k-1])))
```
