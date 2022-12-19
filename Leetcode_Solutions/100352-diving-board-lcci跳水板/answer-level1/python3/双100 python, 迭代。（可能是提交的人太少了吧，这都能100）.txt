![Snipaste_2020-02-22_10-42-23.png](https://pic.leetcode-cn.com/26e1f16cb1638f58776264f9cb3ef865f28b8762e36c2dea4e222511905443b6-Snipaste_2020-02-22_10-42-23.png)
```
class Solution(object):
    def divingBoard(self, shorter, longer, k):
        """
        :type shorter: int
        :type longer: int
        :type k: int
        :rtype: List[int]
        """
        if k == 0:
            return []
        if shorter == longer:
            return [shorter * k]
        
        sol_set = set()
        for i in range(k+1):
            tmp = i*longer + (k-i)*shorter
            if tmp not in sol_set:
                sol_set.add(tmp)

        return sorted(list(sol_set))
            
```

**关键：k块木板由i块shorter和k-i块longer组成，无论如何排列，得到的长度是相同的**

`另外，想请教一下各位老哥，如何使用迭代+记忆化存储优化？`
