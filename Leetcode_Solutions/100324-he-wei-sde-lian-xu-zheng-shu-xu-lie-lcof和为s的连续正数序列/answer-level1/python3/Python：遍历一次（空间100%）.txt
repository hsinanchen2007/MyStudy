思路：动态链搜索，只需遍历一次。按序整数添加至列表，若列表总和等于target，收录该子列表；如果大于target，则用切片操作切去其一个元素，继续判断。
![面试题57.png](https://pic.leetcode-cn.com/ca1169d565223194c8c82d79288b401f7161a15862a328c7b951b5fd61d446d8-%E9%9D%A2%E8%AF%95%E9%A2%9857.png)

```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        allSeq = []
        curSeq = []
        temp = []
        for i in range(1, target//2+2):
            curSeq.append(i)
            if sum(curSeq) == target:
                temp = [j for j in curSeq]
                allSeq.append(temp)
            while sum(curSeq) > target:
                curSeq = curSeq[1:]
                if sum(curSeq) == target:
                    temp = [j for j in curSeq]
                    allSeq.append(temp)
        return allSeq
```
