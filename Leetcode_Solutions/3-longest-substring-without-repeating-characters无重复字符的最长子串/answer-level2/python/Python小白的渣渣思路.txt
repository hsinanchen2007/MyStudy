### 解题思路
self.duoduo函数  判断从当前元素开始不重复的最长子字符串长度

然后在lengthOfLongestSubstring中循环整个字符串，不断去掉前一个元素

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        else:
            ddd = []
            ddNew = [a for a in s]
            while s:
                ddd.append(self.duoduo(ddNew))
                try:
                    ddNew.pop(0)
                except:
                    break    
            return max(ddd)

    def duoduo(self, sNew):

        dd = []
        for i in range(len(sNew)):
            if sNew[i] not in dd:
                dd.append(sNew[i])
                continue
            else:
                break
        return len(dd)
        

```