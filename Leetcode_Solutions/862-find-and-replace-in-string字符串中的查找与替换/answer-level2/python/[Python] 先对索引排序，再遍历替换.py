indexes未必有序，所以先排序，并将排序顺序应用到sources和targets上。
替换时注意追加上前一次替换后剩余的部分。

```
class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        
        # sort by indexes
        sorted_indexes = sorted(range(len(indexes)), key=lambda k: indexes[k])
        indexes = [indexes[i] for i in sorted_indexes]
        sources = [sources[i] for i in sorted_indexes]
        targets = [targets[i] for i in sorted_indexes]
        
        T = []
        last_pos = 0
        for i,start in enumerate(indexes):
            src, tgt = sources[i],targets[i]
            src_len = len(src)
            if S[start:start+src_len] == src:
                T.append(S[last_pos:start])
                T.append(tgt)
                last_pos = start+src_len
        T.append(S[last_pos:])
        return ''.join(T)
```