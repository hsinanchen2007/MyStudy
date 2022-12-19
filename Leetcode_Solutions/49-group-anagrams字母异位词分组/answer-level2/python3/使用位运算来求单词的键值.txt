## 思路
一个单词内每个字母的出现字数必然是有限的，那么用来表示这一个字母所需要的位数也必然是有限的。那么假设样例中字母在单词中出现的最大个数为`step`，令`k=ceil(log2(step))`，那么：
```python []
number = 0
for char in s:
    number += 1<<((ord(char)-97)*k)
```
所得到的数对于每一组单词一定是唯一的。因而可直接用这个得到的数作为Hash表的键值。

## 完整代码
```python []
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = dict()
        for s in strs:
            number = self.str2str(s)
            if number in res:
                res[number].append(s)
            else:
                res[number] = [s]
        return list(res.values())
    def str2str(self, s: str) -> str:
        number, step = 0, 3
        for char in s:
            number += 1<<((ord(char)-97)*step)
        return number
```