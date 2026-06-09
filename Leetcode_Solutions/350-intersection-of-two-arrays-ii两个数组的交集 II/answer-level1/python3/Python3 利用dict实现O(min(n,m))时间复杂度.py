### 解题思路
python中的dict底层上是用哈希表。因此新建和查询的时间复杂度为O(1)
第一步，判断两个数组中较小的那个，建立dict（节约空间）。key=数组成员，value=成员出现的次数
第二步，遍历另一个数组，若存在dict[y]>=1则将dic[y]-1,y加入结果数组中。
第一部分时间复杂度为O(min(n,m)),空间复杂度为O(min(n,m))
第二部分的时间复杂度为O(max(n,m))，空间复杂度为O(1)
整体时间复杂度为O(max(n,m)),空间复杂度为O(min(n,m))
### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) >= len(nums2):
            a = nums2
            b = nums1
        else:
            a = nums1
            b = nums2
        dic = {}
        for x in a:
            dic[x] = dic.get(x, 0) + 1
        result = []
        for y in b:
            if dic.get(y, -1) >= 1:
                dic[y] -= 1
                result.append(y)
        return result
```