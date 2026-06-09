```
class Solution:
    def diStringMatch(self, S: str) -> list:
        N = list(range(len(S)+1))
        result = []
        low,high = 0,len(S)
        while low<high:
            for i in S:
                if i =='I':
                   result.append(N[low])
                   low += 1
                elif i == 'D':
                    result.append(N[high])
                    high -= 1
        result.append(low)
        return result
```

答题思路是low指针指向I的数值，从前往后遍历，遇到I就将当前指到的数添加到列表中，high与之相反