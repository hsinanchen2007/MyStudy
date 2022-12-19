```python []
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(s) == 0 or len(words) == 0:
            return []
        
        cnt = {}
        m = len(words)
        n = len(words[0])
        ans = []
        
        for word in words:
            if cnt.get(word) is None:
                cnt[word] = 1
            else:
                cnt[word] += 1
        
        for i in range(0,len(s)-m*n+1):
            copy = {}
            isMatch = True
            for j in range(0,m):
                key = s[(i+j*n):(i+(j+1)*n)]
                if cnt.get(key) is None:
                    isMatch = False
                    break
                
                if copy.get(key) is None:
                    copy[key] = 1
                else:
                    copy[key] += 1
                
                if copy[key] > cnt[key]:
                    isMatch = False
                    break
            
            if isMatch:
                ans.append(i)
        
        return ans
```

