
思路：
    任何时刻都选择当前存量最多的字符
    例外：当前两个字符相同时，将该字符排除在候选之外
    初始存量优化：任何单一字符最大数量必须小于（另外两个字符+1）*2，如‘aabaabaacaa',b与c插入到a序列中，a的数量最多为8。
实现：
```
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        # 更新初始存量，根据插空规则修正单个字符最大可能的数量
        d = {'a':min(a,2*(b+c+1)),'b':min(b,2*(a+c+1)),'c':min(c,2*(b+a+1))}
        # 修正后的数量确保可以全部用在结果中，求和计算字符串总长
        n = sum(d.values())
        # 维护结果列表
        res = []
        # 单次插入一个字符，根据长度循环
        for _ in range(n):
            # 候选的字母
            cand = set(['a','b','c'])
        `   # 如果列表最后两个字符相同，根据规则不能插入连续三个，故将该字符从候选中删除
            if len(res)>1 and res[-1]==res[-2]:
                cand.remove(res[-1])
            # 贪心，在候选中选择存量最大的字符
            tmp = max(cand,key=lambda x:d[x])
            # 将它加到结果里
            res.append(tmp)
            # 把它的剩余计数减去1. 开始下一轮
            d[tmp] -= 1
        return ''.join(res)
```
