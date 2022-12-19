### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        resMap = {}
        for word in strs:
            word2list = list(word)
            word2list.sort()
            list2str=''.join(word2list)
         
            if list2str not in resMap:
                resMap[list2str] = [word]
            else:
                resMap[list2str].append(word)
        
        res = []
        for key in resMap.keys():
            res.append(resMap[key])
            
        return res
             

```