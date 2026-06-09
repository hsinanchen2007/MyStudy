
![QQ浏览器截图20191215131047.png](https://pic.leetcode-cn.com/7eb77545d39016034750bef80c9cc955d499db6f311ee31c70a3a67996df3533-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20191215131047.png)


def numRabbits(self, answers: List[int]) -> int:
        from collections import Counter
        import math
        dict_ = {}
        dict_ = Counter(answers)
        count = 0
        L = sorted(dict_.items(), key = lambda x: x[0])
        for i in range(len(L)):

            count += math.ceil(L[i][1] / (L[i][0]+1))*(L[i][0]+1)
        return count
        