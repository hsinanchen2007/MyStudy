### 解题思路
首先求对数组升序排序，然后用去重数组得到一个新数组，遍历次数组，求出新数组各元素的个数，最后遍历新数组，
判断数组中元素的值与值的个数是否相等
### 代码

```python3
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        arr.sort(reverse=False)
        cut = list(set(arr))
        L = []
        luck_num = -1
        for i in cut:
            L.append(arr.count(i))
        for i in range(len(cut)):
            if cut[i] == L[i]:
               luck_num = cut[i]
        return luck_num
```