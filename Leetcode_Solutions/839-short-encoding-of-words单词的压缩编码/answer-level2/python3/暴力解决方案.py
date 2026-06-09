### 解题思路
贪心处理，保留比较长的，短的加入时，判定时候已经存在就可以了

### 代码

```python3
class Solution:
    def cmp_to_key(self, mycmp):
        """Convert a cmp= function into a key= function"""
        class K(object):
            __slots__ = ['obj']
            def __init__(self, obj):
                self.obj = obj
            def __lt__(self, other):
                return mycmp(self.obj, other.obj) < 0
            def __gt__(self, other):
                return mycmp(self.obj, other.obj) > 0
            def __eq__(self, other):
                return mycmp(self.obj, other.obj) == 0
            def __le__(self, other):
                return mycmp(self.obj, other.obj) <= 0
            def __ge__(self, other):
                return mycmp(self.obj, other.obj) >= 0
            __hash__ = None
        return K
    
    def cmp(self, a, b):
        """
        给出a>b的情况
        此时的排序情况是从小到大
        """
        if len(a) > len(b):
            return 1
        elif len(a) < len(b):
            return -1
        return 0
    
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=self.cmp_to_key(self.cmp), reverse=True)
        cur_len = 0
        S = []
        for i in range(0, len(words)):
            word = words[i]
            flag = True
            for j in range(0, len(S)):
                # print(S[j][-len(word):])
                if S[j][-len(word):] == word:
                    flag = False
                    break
            if flag:
                S.append(word)
                cur_len += len(word) + 1
        return cur_len
                
```