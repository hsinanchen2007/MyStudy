```
class Solution:
    def shortestSeq(self, big: List[int], small: List[int]) -> List[int]:
        import sys
        if len(big) < len(small):
            return []
        smallset, bigset, Map, count, dp_length = set(), set(), {}, 0, sys.maxsize #集合的重要性
        index, res = [], [-1, -1]
        for i in small:
            smallset.add(i) #必要步骤，用列表必超时
        for i in range(len(big)):
            if big[i] in smallset:
                index.append(i) #这是索引来的
                bigset.add(big[i])
                if big[i] in Map:
                    Map[big[i]] += 1
                else:
                    Map[big[i]] = 1
                if len(bigset) == len(smallset):
                    while True:
                        tmp = index.pop(0) #必须是pop(0)，像队列一样先进先出
                        count = Map[big[tmp]] - 1
                        Map[big[tmp]] = count
                        if count == 0:
                            bigset.remove(big[tmp])
                            break
                    if dp_length > i - tmp + 1: #Python的最大数用了sys.maxsize
                        dp_length = i - tmp + 1
                        res[0] = tmp
                        res[1] = i
        if res[0] < 0:
            return []
        return res
```
