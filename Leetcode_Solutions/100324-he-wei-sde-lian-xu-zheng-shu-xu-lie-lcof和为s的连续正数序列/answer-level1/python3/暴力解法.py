### 解题思路
暴力不提倡，但可以解决问题
面对问题不要慌，敢于分析动笔

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res=list()
        for i in range(1,target):
            tmp=i
            for j in range(i+1,target):
                if tmp+j<target:
                    tmp+=j
                elif tmp+j==target:
                    res.append([x for x in range(i,j+1)])
                else:
                    break
        return res

```