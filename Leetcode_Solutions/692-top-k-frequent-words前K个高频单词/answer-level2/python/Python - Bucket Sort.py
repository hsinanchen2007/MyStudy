### 解题思路
其中字母顺序排序做的不是很好
如果不考虑字母序,时间复杂度可以做到O(n)
因为字母顺序排序涉及到的量级比较小,对总的时间影响不是很大

执行用时 :32 ms, 在所有 Python3 提交中击败了100.00% 的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了26.67%的用户

### 代码

```python3
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        if not words: return []
        hashmap = {}
        for word in words:
            if word in hashmap:
                hashmap[word] += 1
            else:
                hashmap[word] = 1
        bucket = [[] for _ in range(len(words)+1)]
        for word in hashmap:
            bucket[hashmap[word]].append(word)
        res = []
        for i in range(len(bucket)-1,-1,-1):
            bucket[i].sort(reverse = True)
            while k > 0 and bucket[i]:
                res.append(bucket[i].pop())
                k -= 1
        return res
```