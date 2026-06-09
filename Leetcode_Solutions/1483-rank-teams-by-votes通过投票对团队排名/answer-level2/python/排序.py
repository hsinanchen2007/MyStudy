### 解题思路
队伍最多有26个，且用大写字母表示，故创建一个二维数组[26]*[n]（n就是实际参加的队伍个数加1），用来存储这26个队伍的排名数据。如：有3个队伍，分别为A，B，C，那么n就是4，[0][0]表示A队获得‘排位第一’的票数，[0][1]表示A队获得’排位第二‘的票数，以此类推。。。最后的[0][4]表示A队的编号，用于字母顺序排序。
再将这个二维数组降序排序，得到的数组就是我们希望的结果。

### 代码

```python
class Solution(object):
    def rankTeams(self, votes):
        """
        :type votes: List[str]
        :rtype: str
        """
        res = ''
        score = [[0 for i in range(len(votes[0])+1)] for x in range(26)]
        for vote in votes:
            for i, v in enumerate(vote):
                score[ord(v) - ord('A')][i] += 1
                score[ord(v) - ord('A')][-1] = ord('Z') - ord(v) + 1  # 存储字母对应的数字，如A:26,B:25 ...
        score.sort(reverse=True)
        for i in range(26):
            if score[i][-1] != 0:
                res += chr(26 - score[i][-1] + 65)
        return res
```