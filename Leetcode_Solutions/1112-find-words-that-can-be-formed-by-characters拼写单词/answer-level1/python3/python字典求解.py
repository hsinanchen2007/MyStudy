### 解题思路
由于每个字母只能用一次，因此需要记录字母出现的次数

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ret, set_ = 0, {}
        for i in chars:
            set_[i] = 1 if i not in set_ else set_[i] + 1
        for i in words:
            flag, temp = 0, set_.copy()
            for j in i:
                if j not in temp or temp[j] == 0:
                    flag = 1
                    break
                else:
                    temp[j] -= 1
            if flag == 0:
                ret += len(i)
        return ret
```