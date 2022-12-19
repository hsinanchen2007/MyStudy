#### 纠结了好久的地方在于`S[fast+1:fast+2]`, 利用Python list切片不会导致下标越界
```
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        slow, fast, ans = 0, 0, []
        for i in range(len(S)):  
            if S[i] != S[fast]:
                fast = slow = i
            else:
                fast = i  
            if fast - slow >= 2 and S[fast] != S[fast+1:fast+2]:
                ans.append([slow, fast])    
        return ans
```
![image.png](https://pic.leetcode-cn.com/5946d0a4be37511275e474036f375f084922f47db375663f2299b28059bb9617-image.png)



