### 解题思路
贪心算法：身高矮的元素不会对身高高的元素的相对排位产生影响
第一步：将people数组按照身高降序，前人数升序整体排序
第二步：将people数组中的每个元素插入res数组的该元素前人数的位置
整体思路：先排序身高高的元素，再排序升高矮的元素
### 代码

```python
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        if people:
            people.sort(key=lambda x: (-x[0], x[1]))

            for i in people:
                res.insert(i[1], i)

        return res
```