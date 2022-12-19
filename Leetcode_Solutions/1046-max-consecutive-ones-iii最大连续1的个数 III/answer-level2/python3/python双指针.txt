
```python []
class Solution(object):
    def longestOnes(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        max_len = 0
        temp = 0
        startIndex = 0
        endIndex = 0
        while endIndex < len(A):
            if A[endIndex] == 1:
                temp +=1
                endIndex += 1
            else:
                if K > 0:
                    temp += 1
                    K -= 1
                    endIndex += 1
                else:
                    if A[startIndex] == 1:
                        on_off = True
                        while on_off and startIndex <= endIndex:
                            if A[startIndex] == 0:
                                on_off = False
                            startIndex +=1
                            temp -=1
                    else:
                        startIndex += 1
                        temp -= 1
                    K += 1
                
            max_len = max(max_len, temp)
        return max_len
```

