### 解题思路
对每个字符串排序后加入字典即可，暴力求解

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        res_ = {}
        for word in strs:
            tmp = "".join((lambda x:(x.sort(),x)[1])(list(word)))
            if tmp not in res_.keys():
                res_[tmp] = [word]
            else:
                res_[tmp] += [word]
        for key in res_.keys():
            res.append(res_[key])
        return res
```