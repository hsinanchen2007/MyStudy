### 解题思路
田忌赛马，首先排序两个数组，然后一一比对，如果a比b大，那么a后面的所有数字都比b大 ---> 说明a是大于b的数字中最小的一个数字
然后按照原顺序把答案映射回去
### 代码

```python3
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        sortA=sorted(A)
        sortB=sorted(B)
        assign={b:[] for b in B}
        remain=[]
        j=0
        for nA in sortA:
            if nA>sortB[j]:
                assign[sortB[j]].append(nA)
                j+=1
            else:
                remain.append(nA)
        return [assign[b].pop() if assign[b] else remain.pop() for b in B]
```