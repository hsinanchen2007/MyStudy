使用一个字典, 数字与字符数目的差值diff作为key, value是前i个数的差值为key的起始下标
只需要存1个下标, 遇到新的下标的时候直接判断是否要更新s和e即可
**注意需要额外处理diff=0的情况**
**注意结果是[s+1:e]**
**注意输入存在多位数字的情况..**
```python
class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        diffToStartIndex = {}
        diff = 0
        s, e = 0, -1
        for i, c in enumerate(array):
            if '0' <= c[0] <= '9':
                diff += 1
            else:
                diff -= 1
            if diff == 0 and i > e - s:
                s, e = -1, i
            if diff not in diffToStartIndex:
                diffToStartIndex[diff] = i
            elif i - diffToStartIndex[diff] > e - s:
                s, e = diffToStartIndex[diff], i
        return array[s + 1:e + 1]
```
