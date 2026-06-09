![b54f564675b7e7d043432b6d922ca00.png](https://pic.leetcode-cn.com/e8b9b9daa3af24ebe61fcf6039e539a7909e950eccfc35084de24fe91ae07a2a-b54f564675b7e7d043432b6d922ca00.png)
提供两种**大同小异**的思路，都是**字典储存**，效率都比较高。

**思路一**
```python []
from collections import defaultdict


class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        # 建立字典储存A的信息，key是A的数值，val是这个数值的index的列表   
        A_mapping = defaultdict(list)
        for i, num in enumerate(A):
            A_mapping[num].append(i)
        max_len = 2
        n = len(A)
        # 两层遍历，对于每个i，j看以A[i],A[j]为前两项的等差数列有几项。
        for i in range(n):
            for j in range(i+1, n):
                d = A[j] - A[i]
                length = 2
                while True:
                    if A[j] + d not in A_mapping:
                        break
                    key = False
                    for k in A_mapping[A[j] + d]:
                        if k > j:
                            key = True
                            break
                    if not key:
                        break
                    j = k
                    length += 1
                    max_len = max(max_len, length)
        return max_len
```

**思路二** DP
```python []
from collections import defaultdict


class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        # 建立字典储存A的信息，key是A的数值，val是这个数值的index的列表        
        A_mapping = defaultdict(list) 
        for i, num in enumerate(A):
            A_mapping[num].append(i)
        #  建立dp变量，dp[i][j]表示到A[i], A[j]的等差数列到第几项了
        dp = defaultdict(lambda: defaultdict(int))
        n = len(A)
        for i in range(n):
            for j in range(i+1, n):
                if A[j] * 2 - A[i] in A_mapping: 
                    key = False
                    for k in A_mapping[A[j] * 2 - A[i]]:
                        if k > j:
                            key = True
                            break
                    if key:
                        # 值得注意的是，j，k不可以被i，j刷新，而是要max刷新，因为有重复元素存在的关系
                        dp[j][k] = max(dp[j][k], dp[i][j] + 1)
                        
        try:
            return max(dp[i][j] for i in dp for j in dp[i]) + 2
        except ValueError:
            return 2
```
理论上思路二比思路一块，因为思路二对于每个i，j只处理了一步O(1)，不像思路一里面要循环到底O(n)，但跑下来也差不多，可能跟测试集有关系