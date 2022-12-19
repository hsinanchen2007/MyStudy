### 解题思路
建立两个字典G1,G2，key分别是被信任的，信任别人的，如果G1中有一个key的value有N-1个，且不在G2的key中，那就是法官，注意只有1个人，trust为空的情况，这个人也是法官。


### 代码

```python3
from collections import defaultdict
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N==1 and trust==[]:
            return 1
        G1=defaultdict(list)
        G2=defaultdict(list)
        for list1 in trust:
            G1[list1[1]].append(list1[0])
        for list2 in trust:
            G2[list2[0]].append(list2[1])
        for i in G1.keys():
            if len(G1[i])==N-1 and i not in G2.keys():
                return i
        return -1

```