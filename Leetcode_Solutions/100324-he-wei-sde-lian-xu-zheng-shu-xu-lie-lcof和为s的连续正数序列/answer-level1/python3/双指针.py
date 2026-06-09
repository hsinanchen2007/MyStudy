```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        def func(start , end):
            return [i for i in range(start, end+1)]
        def sum_(start, end):
            return   (end-start+1) * ( end + start) // 2
        start = 1
        end = 2
        ans = []
        while start < end:
            if sum_(start, end) < target: end +=1
            elif sum_(start, end) > target: start +=1 
            else:
                ans.append(func(start, end))
                start +=1
        return ans 
```
