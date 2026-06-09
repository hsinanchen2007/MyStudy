# 思路
1. dic1[num] 记录含有num的所有doc的id
2. 对每一个id数组，两两元素记录到dic2[i, j]，即为docs[i]与docs[j]的交集大小
```
class Solution:
    def computeSimilarities(self, docs: List[List[int]]) -> List[str]:
        dic1 = collections.defaultdict(list)
        for i, doc in enumerate(docs):
            for num in doc:
                dic1[num].append(i)
        dic2 = collections.defaultdict(int)
        for li in dic1.values():
            for p in range(len(li)):
                for q in range(p + 1, len(li)):
                    dic2[li[p], li[q]] += 1
        res = []
        minn = 1e-9
        for (p, q), i in dic2.items():
            u = len(docs[p]) + len(docs[q]) - i
            res.append("{0:d},{1:d}: {2:.4f}".format(p, q, i / u + minn))
        return res
```
