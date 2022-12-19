### 解题思路
- 思路：
1. 先考虑特殊情况：空列表，返回空字符串；
2. 如果列表非空，对列表进行排序，以单词长度为关键词进行排序，将长度最小的元素放在索引0。以第一个单词为比较对象，逐个比较每一个单词的前缀是否相同。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        count = 1                           #设置计数器
        if len(strs) == 0:
            return ""
        strs.sort(key=lambda x:len(x))
        target = strs[0]
        flag = True                         #设置比较标志flagflag
        while flag and count <= len(target):
            for word in strs:
                if target[:count:] != word[:count:]:
                    flag = False            #不符合情况，跳出循环
                    break
            else:
                count += 1
        
        if 1 == count:
            return ''
        else:
            return target[:count-1:]
```