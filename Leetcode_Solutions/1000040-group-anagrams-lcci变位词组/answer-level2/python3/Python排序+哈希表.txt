先将每个单词进行排序，变位词经过排序后变为同一个词，遍历原始列表，利用哈希表存储已访问的变位词，键值为其在结果列表中的位置。Python代码如下：
```python []
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        tmp = []
        for word in strs:
            tmp.append(''.join(sorted(word)))
        dic = {}
        ans = []
        for i in range(len(tmp)):
            if tmp[i] not in dic:
                ans.append([strs[i]])
                dic[tmp[i]] = len(ans) - 1
            else:
                ans[dic[tmp[i]]].append(strs[i])
        return ans
```