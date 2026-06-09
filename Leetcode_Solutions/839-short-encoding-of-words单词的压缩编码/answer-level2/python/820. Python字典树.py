### 解题思路
这道题很明显是要找相同后缀的问题，而找后缀我们可以看成是逆序的找前缀，自然也就想到用字典树。

### 代码

```python3
class Node:
    def __init__(self, flag=0):
        self.flag = flag
        self.next = {}
        # self.word = '' # 本例用不到

class Solution(object):
    def minimumLengthEncoding(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        if words == []:
            return 1
        root = Node()
        # 建立字典树
        for word in words:
            word = word[::-1]
            tmp = root
            for ch in word:
                if ch not in tmp.next:
                    tmp.next[ch] = Node()
                tmp = tmp.next[ch]
            tmp.flag = 1
        # 遍历字典树
        cnt = 0
        def get_res(root, num):
            nonlocal cnt
            if root.next == {}:
                cnt += num + 1
            for ch in root.next:
                get_res(root.next[ch], num + 1)
        get_res(root, 0)
        return cnt
```