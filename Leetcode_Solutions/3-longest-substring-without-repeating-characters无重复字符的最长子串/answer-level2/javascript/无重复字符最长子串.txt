应该挺容易理解吧

```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0;i = 0
        for j in range(len(s)):
            if s[j] not in s[i:j]:
                res = max(res,j+1-i)
            else:
                i += s[i:j].index(s[j]) + 1
        return res
```
```javascript []
var lengthOfLongestSubstring = function(s) {
    let i=0, res=0, n=0;
    for (let j = 0; j < s.length; j++){
        n = s.slice(i,j).indexOf(s[j])
        if (n == -1){
            res = Math.max(res,j+1-i);
        }else{
            i += n+1;
        }
    }
    return res;
};
```
