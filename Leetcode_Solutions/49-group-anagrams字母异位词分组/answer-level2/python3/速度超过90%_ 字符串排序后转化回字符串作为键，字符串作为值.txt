```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = dict()
        for s in strs:
            # 转化为列表后排序不会破坏原来的字符串
            scopy = str(sorted(s))
            if scopy in hashmap:
                hashmap[scopy].append(s)
            else:
                hashmap[scopy] = [s]
        return [value for value in hashmap.values()]
            
```
