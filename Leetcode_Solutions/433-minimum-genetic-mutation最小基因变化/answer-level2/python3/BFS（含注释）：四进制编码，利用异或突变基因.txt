```
class Solution(object):
    def minMutation(self, start, end, bank):
        def toNumber(gene):
            table = {v : i for i, v in enumerate('ATGC')}
            return sum([table[g] * 1 << (2 * i) for i, g in enumerate(gene)])
        bank = set(map(toNumber, bank))
        print(bank)
        start = toNumber(start)
        end = toNumber(end)
        queue = [(start, 0)]
        viset = set([start])
        while queue:
            gene, step = queue.pop(0)
            if gene == end:
                return step
            for x in range(8):
                for y in range(4):
                    next = gene ^ (y << (x * 2))
                    #这里是gene的某个四进制位上的值分别与0,1,2,3异或
                    #分别异或可以实现某个位的突变，比如：
                    #gene某位是2，则分别与0,1,2,3异或值为：2,3,0,1
                    #这样做比直接更改基因位来得方便许多
                    if next in bank and next not in viset:
                        viset.add(next)#使用过此序列则加入
                        #如果符合基因库则加入bfs列表，准备下一次的比对
                        queue.append((next, step + 1))
        return -1
```
