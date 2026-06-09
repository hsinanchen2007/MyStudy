### 解题思路
此处撰写解题思路
一开始用列表解析和set实现，但是当测试用例是aa,a的时候发生了错误，原来不能去重，那么只有排序了
### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 解法1： 纯原生实现，统计每个字符串中字符出现个数，然后比较字典是否相同
        # dictc = {}
        # for i in s:
        #     if i in dictc:
        #         dictc[i] += 1
        #     else:
        #         dictc[i] = 1
        # c = {}
        # for j in t:
        #     if j in c:
        #         c[j] += 1
        #     else:
        #         c[j] = 1
        # flag = True if c == dictc else False
        # return flag
        # 解法2 取巧方法 利用Counter直接生成每个字符出现次数的字典
        from collections import Counter
        return Counter(s) == Counter(t) false
```