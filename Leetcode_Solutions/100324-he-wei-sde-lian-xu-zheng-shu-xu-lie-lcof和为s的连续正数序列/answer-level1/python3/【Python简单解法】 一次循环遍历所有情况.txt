### 解题思路
1、需要遍历所有情况，首先需要明白的几个点：
    - 当前取得数不可能大于target，
    - 当前连续几个数得和小于target时才继续添加下一个数，如果大于target，直接进行下一次循环遍历
    - 当连续几个数等于得时候，就添加到res中
    - j:控制内部循环从第几个数开始取，第一轮时取1，2，3，4，5....，第二轮就从2,3,4,5...,第三轮就从3,4,5,6....,第j轮就从j,j+1,j+2......
    - i:控制内部循环，直接在(j,target)直接取值，判断是否和target相等
    - 方法缺点：时间复杂度高，但是能通过

### 代码

```python3

class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        a= []
        j = 1
        while j < target:
            for i in range(j,target):
                a.append(i)
                # print(a)
                if sum(a)==target:
                    res.append(a)
                    # a = []
                    break
                elif sum(a)<target:
                    continue
                else:
                    break
            j+=1
            a = []

        return res

```