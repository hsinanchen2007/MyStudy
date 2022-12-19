### 解题思路
```
var longestPalindrome = function(s) {
    let count = 0;
    let map = new Map();
    for(let i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i],map.get(s[i])+1)
        }else{
            map.set(s[i],1);
        }
    }
    let isHaveSingle = false;
    for(let [key,value] of map.entries()){
        if(value%2==0){
            count += value
        }else{
            count += value-1;
            isHaveSingle = true
        }
    }
    return isHaveSingle?count+1:count;
};
```

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import Counter
        smap = Counter(s)
        count = 0
        isHaveSingle = False
        for key in smap:
            if smap[key] %2 == 0:
                count += smap[key]
            else:
                count += smap[key]-1
                isHaveSingle = True

        return count+1 if isHaveSingle else count
```