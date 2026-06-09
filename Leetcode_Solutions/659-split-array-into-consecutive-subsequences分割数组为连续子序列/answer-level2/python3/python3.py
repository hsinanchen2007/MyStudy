### 解题思路
1.最关键是最小索引从哪里开始
2.注意数组中不连续该怎么判断
3.return false的条件（start+2）
4.满足最小索引条件后还要满足结尾索引条件

### 代码

```python3
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        """
        关心最小的索引start从哪里开始和结束
        """
        pre,precount=None,0
        start=collections.deque()
        for t,group in itertools.groupby(nums):#中间有断隔
            num=len(list(group))
            if pre is not None and t-pre!=1:
                for _ in range(precount):
                    if pre<start.popleft()+2:
                        return False
                pre,precount=None,0 
            if pre is None or t-pre==1:
                if num-precount>0:#说明t要作为某一序列的开头
                    for _ in range(num-precount):
                        start.append(t)
                elif num-precount<0:
                    for _ in range(precount-num):
                        if t<start.popleft()+2+1:
                            return False
            pre,precount=t,num   
        return all(nums[-1]>=x+2 for x in start)

```