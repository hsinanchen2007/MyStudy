### 解题思路
思路就是先排序，按照每个列表中的第一个元素进行从小到大排序，之后有交集，只要把当前数组的右边界更新为新的右边界即可，无交集则把之前
的列表插入res，并且给其赋予新的值，最后循环结束再把tempArr插入res即可

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # 如果给定列表为空则返回空列表
        if not intervals :
            return []
        # 将给定列表按照每个列表的第一个数字进行排序
        sortArr = sorted(intervals, key=lambda x: x[0])
        res = []
        # 初始一个tempArr
        # 假设每个列表第一个元素为x， 第二个元素为y
        tempArr = sortArr[0]
        ls = len(sortArr)
        for i in range(1, ls) :
            # 如果当前列表的y大于tempArr中的y 并且 x 小于tempArr的y， 即他们有交集， 此时更新tempArr中的y为当前列表的y
            if sortArr[i][1] >= tempArr[1] and sortArr[i][0] <= tempArr[1] :
                tempArr[1] = sortArr[i][1]
            # 如果当前列表的x 大于 tempArr的y，即没有交集
            # 将tempArr插入res中，更新tempArr的值
            elif sortArr[i][0] > tempArr[1] :
                res.append(tempArr)
                tempArr = sortArr[i]
        # 循环完成之后把tempArr中的值插入res
        res.append(tempArr)
        return res
```