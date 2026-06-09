### 解题思路
用哈希保存每一个状态中，各个字符是否还存在

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        res = []
        # 创建哈希表，并统计各个字符的个数
        dict_ = {}
        for c in s:
            if c not in dict_:
                dict_[c] = 0
            dict_[c] += 1

        tmp = []

        def isBackTracking(res, dict_, tmp, k):
            if k == 0:
                res.append(''.join(tmp))
                return

            for key in dict_:
                if dict_[key] > 0:
                    tmp.append(key)
                    dict_[key] -= 1  # 每次迭代时，哈希表中对应的字符(key)个数减一
                    isBackTracking(res, dict_, tmp, k-1)
                    dict_[key] += 1  # 哈希表中对应的字符(key)个数加一，恢复上个状态
                    tmp.pop()

        isBackTracking(res, dict_, tmp, len(s))

        return res
            
```