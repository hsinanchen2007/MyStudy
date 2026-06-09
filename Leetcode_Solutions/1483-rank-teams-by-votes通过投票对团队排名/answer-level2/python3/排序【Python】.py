### 思路

**排序**

```
创建一个二维数组 score[26][n+1]。
拿示例一举例：
score[0][0]：表示 A 队排位第一的票数。
score[0][1]：表示 A 队排位第二的票数。
...
score[0][-1]：表示 A 队的编号，排序基于这个。
然后降序排序，最后数字转换成字母就好了。
```

**时间复杂度:** O(m\*n)，m 是投票人个数，n 是参赛队伍数量 。
**空间复杂度:** O(26\*(n + 1))，n 是参赛队伍数量 。

##### Python3代码

```python
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        # create score[26][n+1]
        score = [[0 for i in range(n+1)] for x in range(26)]
        for vote in votes:
            for i, v in enumerate(vote):
                score[ord(v) - ord("A")][i] += 1
                score[ord(v) - ord("A")][-1] = ord("Z") - ord(v) + 1  # A:26 B:25 ··· sort based on it
        score.sort(reverse=True)
        ans = ""
        for i in range(26):
            if score[i][-1] != 0:
                ans += chr(26 - score[i][-1] + 65)  # int to char
        return ans
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1366-Rank-Teams-by-Votes/1366.py)

### 参考

[coder233 题解](https://leetcode-cn.com/problems/rank-teams-by-votes/solution/pai-xu-by-coder233/263056/)