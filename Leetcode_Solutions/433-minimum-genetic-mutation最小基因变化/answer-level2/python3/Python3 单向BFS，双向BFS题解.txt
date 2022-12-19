#单向BFS，标准BFS写法，一层一层扫描
```python
class Solution:
    def minMutation(self, start, end, bank):
        if end not in bank:
            return -1
        bank = set(bank)
        change = {'A': 'TCG', 'T': 'ACG', 'C': 'ATG', 'G': 'ATC'}
        q = [(start, 0)]
        while q:
            node, length = q.pop(0)
            if node == end:
                return length
            for i, v in enumerate(node):
                for j in change[v]:
                    new = node[:i] + j + node[i + 1:]
                    if new in bank:
                        q.append((new, length+1))
                        bank.remove(new)
        return -1
```

#双向BFS
```python
class Solution:
    def minMutationTwo_end_bfs(self, start, end, bank):
        if end not in bank:
            return -1
        begin = {start}
        end = {end}
        beginStrLen = len(start)
        bank = set(bank)
        length = 0
        change = {'A': 'TCG', 'T': 'ACG', 'C': 'ATG', 'G': 'ATC'}
        while begin and end:
            length += 1
            nextGenSet = set()
            for gen in begin:
                for i in range(beginStrLen):
                    for j in change[gen[i]]:
                        if j != gen[i]:
                            nextGen = gen[:i] + j + gen[i + 1:]
                            if nextGen in end:
                                return length
                            if nextGen in bank:
                                nextGenSet.add(nextGen)
                                bank.remove(nextGen)
            begin = nextGenSet
            if len(end) < len(begin):
                end, begin = begin, end
        return -1
```
# 测试
```python
if __name__ == "__main__":
    start = "AACCTTGG"
    end =   "AATTCCGG"
    bank =  ["AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"]
    res = Solution().minMutationTwo_end_bfs(start, end, bank)
    print(res)
```

这套写法可以套用不少题，比如[127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)等