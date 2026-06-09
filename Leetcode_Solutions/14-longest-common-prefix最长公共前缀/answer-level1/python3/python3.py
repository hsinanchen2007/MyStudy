### 解题思路
1.把zip(*)的结果转换成list
2.匹配list的每个元素i第一个字母的个数是否等于len(i)

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        list1 = list(zip(*strs))
        maxstr = ""
        for i in list1:
            if i.count(i[0]) == len(i):
                maxstr += i[0]
            else:
                break
        return maxstr



```