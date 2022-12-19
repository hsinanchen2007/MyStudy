### 解题思路
思路比较简单直接：
- 遍历字符串列表中的每一个字符，记为Si；
- 分别将Si的第一个字符放入集合中，利用集合的唯一性来判断是否是公共字符；
- 若是公共字符，则将其从字符串Si中剔除掉，进行下一个字符的判断；
- 需要注意的是，如果有字符串为空，则表示不再有公共字符出现，此时应终止所有循环；

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lgth = len(strs)
        nums = lgth + 0
        rst = ''
        flag = True
        while flag:
            tmp = set()
            for i,item in enumerate(strs):
                if not item:
                    flag = False
                    break
                tmp.add(item[0])
                strs[i] = item[1:]
            cnt = len(tmp)
            if not flag or cnt == 0:
                break
            if len(tmp) > 1:
                break
            else:
                rst += tmp.pop()
        return rst
```