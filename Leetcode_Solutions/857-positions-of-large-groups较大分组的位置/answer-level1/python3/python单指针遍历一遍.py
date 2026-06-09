```
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        count = 1
        ans = []
        for i in range(len(S)-1):
            if S[i] == S[i+1]:
                count += 1
            else:
                if count >= 3:
                    ans.append([i-count+1,i])
                    count = 1
                else:
                    count = 1
        if count >= 3:
            ans.append([i-count+2,i+1])
        return ans
```
