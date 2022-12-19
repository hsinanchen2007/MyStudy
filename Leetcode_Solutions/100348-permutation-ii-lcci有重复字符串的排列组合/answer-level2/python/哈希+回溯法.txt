### 解题思路
哈希表————各个字符的个数，作为状态记录，每次向下搜索，只处理个数不为0的字符

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        res = []

        #哈希表————各个字符的个数，作为状态记录
        dict_ = {}
        for i in S:
            if i not in dict_:
                dict_[i] = 0 
            dict_[i] += 1
        
        tmp = []

        def isBackTracking(res, dict_, tmp, k):
            if k == 0:
                res.append(''.join(tmp))
                return

            for key in dict_:
                if dict_[key] > 0:   #每次向下搜索，只处理个数不为0的字符
                    tmp.append(key)
                    dict_[key] -= 1  # 状态更新，对应字符个数减一
                    isBackTracking(res, dict_, tmp, k-1)
                    dict_[key] += 1  # 状态恢复，对应字符个数加一
                    tmp.pop()

        isBackTracking(res, dict_, tmp, len(S))

        return res
```