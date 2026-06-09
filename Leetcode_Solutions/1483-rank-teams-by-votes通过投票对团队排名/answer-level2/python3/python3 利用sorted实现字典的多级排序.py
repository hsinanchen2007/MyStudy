利用字典记录每个候选者和他的选票情况，键为候选者字母，键值为列表，存储第一到最后一名的票数；对于同票数的排序，直接在字典后加一位表示字母大小的数据即可，利用python3的sorted多级排序实现
```
class Solution:
    def rankTeams(self, votes) -> str:
        if len(votes[0])==1 or len(votes)==1:
            return votes[0]
        rank_num=len(votes[0])
        # 这种初始化有问题
        # dic={}.fromkeys(votes[0],[0 for _ in range(rank_num)])
        dic={}
        for v in votes[0]:
            dic[v]=[0 for _ in range(rank_num)]
        for v in votes:
            for i in range(len(v)):
                dic[v[i]][i]+=1
        # print(dic)
        tmp=sorted(dic.items(),key=lambda x:x[1]+[90-ord(x[0])],reverse=True)
        print(dic)
        return "".join([x[0] for x in tmp])
```
![image.png](https://pic.leetcode-cn.com/87c790fd782c1567366b42f5ddbca0ecaf7ed3cf754d3e5f5b0db60e0cf32811-image.png)
