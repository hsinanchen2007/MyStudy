### 解法 1 hash表记录
- 用一个字典`trust_dict`记录所有人的信任列表，最后遍历这个字典找到法官
- `candicate` 是小镇人的列表
- 用`trust_dict.keys() -`candicate` 即为法官候选
- 最后遍历候选法官，找到那个被所有人信任的即为法官
```
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        trust_dict = {}
        candicate = set([i for i in range(1, N+1) ])
        for trust_pair in trust:
            if not trust_pair[0] in  trust_dict:
                trust_dict[trust_pair[0]] = []
            trust_dict[trust_pair[0]].append(trust_pair[1])
        trust_key = set(trust_dict.keys())
        # 如果  len(trust_key) == N 此时所有人都有信任的人，显然不符合要求，如果信任法官的人不足 N-1 说明不是所有人都信任，所以也返回-1
        if len(trust_key) == N or  len(trust_key) != N-1:
            return -1  
        # 没有信任的人的即为法官候选人
        candi_judges = candicate - trust_key

        for candi_judge in candi_judges:
            flag = True
            for key in trust_dict:
                if not candi_judge in trust_dict[key]:
                    flag = False
            if flag:
                return candi_judge
        
        return -1
```
### 出入度计算
- 分别用两个列表`indeg` 和 `outdeg` 记录入度和出度
- 提议的法官要求为法官的要求是入度为`N-1`, 出度为`0`, 满足即为法官
```
def findJudge(self, N: int, trust: List[List[int]]) -> int:
        # 法官的要求是入度为N-1, 出度为0
        indeg = [0] * (N+1)
        outdeg = [0] * (N+1)
        for trust_pair in trust:
            # 入度
            indeg[trust_pair[1]] += 1
            # 出度
            outdeg[trust_pair[0]] += 1 
        
        for i in range(1, N + 1):
            if indeg[i] == N-1 and outdeg[i] == 0:
                return i 
        return -1
```
