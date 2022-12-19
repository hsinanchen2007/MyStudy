### 解题思路
加哈希表这种思路会快一点，当出现重复元素的时候，存储的是下一个合法位置，我们只需要保持s[i:j+1]无重复元素
如果s[j]与前面的元素出现了重复，那么把i更新为max(i,hashmap[s[j]]),因为我们在存储的时候存储的就是
hashmap[s[j]]=j+1，j+1就是下一合法位置，所以我们可以进行这样的替换       

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res=0
        hashmap={}
        i=0
        for j in range(len(s)):
            if s[j] in hashmap:
                i=max(i,hashmap[s[j]])
            res=max(res,j-i+1)
            hashmap[s[j]]=j+1       
        return res


                    




        
```