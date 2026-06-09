```
class Solution:
    def permutation(self, s: str) -> List[str]:
        def arr2str(s):
            res = ''
            for item in s :
                res += item 
            return res 
        def swap(s, start, end):
            while start < end:
                s[start], s[end] = s[end], s[start]
                start+=1
                end -=1

        if not s: return []
        ans = []
        s = [item for item in s]
        s.sort()
        ans.append(arr2str(s)) 
        while True:
            for i in range(len(s)-1, -1, -1):
                if i-1 >= 0  and s[i] <= s[i-1]:
                    continue
                else: break 
            if i -1 < 0: break 
            i = i-1
            for j in range(len(s)-1, i, -1):
                if s[j] > s[i]: break 
            s[i], s[j] = s[j], s[i] 
            swap(s, i+1, len(s)-1)
            ans.append(arr2str(s))
        return ans
```
