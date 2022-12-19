### 解题思路
先取所有的数据组成新的列表，然后按照列间隔，分别划分s列表

### 代码

```python3
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        li = []
        l2 = []
        for i in nums:
            for j in i:
                li.append(j)
        if len(li) !=r*c:
            return nums
        else:
            for i in range(0,len(li),c):
                l2.append(li[i:i+c])
        return l2



        
```