### 解题思路
遍历其中一个数组，判断此数组中的元素：
1.是否在另一个数组里；
2.是否已经在交集中。
同时满足条件后，添加到交集中。
遍历完毕，输出交集。

### 代码

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        array = []
        for m in nums1:
            if m in nums2 and m not in array:
                array.append(m)
        return array
```

