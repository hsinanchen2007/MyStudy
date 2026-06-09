### 解题思路
对每个 string， 计算出一个 hash map， 然后取相同 key 对应的出现次数的较小值。

他人的解法还是比我好，简洁精炼。

### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        hs = dict()
        for x in A[0]:
            if x in hs:
                hs[x] += 1
            else:
                hs[x] = 1
        
        for string in A[1:]:
            tmp = dict()
            for x in string:
                if x in tmp:
                    tmp[x] += 1
                else:
                    tmp[x] = 1
            for x in hs:  # hs 最长也就 26， 也没必要特意去控制其大小
                if x in tmp:
                    hs[x] = min(hs[x], tmp[x])
                else:
                    hs[x] = 0 # del hs[x] 会导致 RuntimeError: dictionary changed size during iteration
        result = []
        for x in hs:
            if hs[x]>0:
                result += [x]*hs[x]
        
        return result

```