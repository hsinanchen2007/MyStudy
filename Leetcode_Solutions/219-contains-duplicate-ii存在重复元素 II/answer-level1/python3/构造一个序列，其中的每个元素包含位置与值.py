- 构造一个序列，其中的每个元素包含位置与值
- 对这个序列，按元素的值进行排序
- 遍历数组
    - 如果相邻元素值相等，判断原位置之差的绝对值（库函数的排序是稳定的，所以比较的原位置之差会尽可能的小）

```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        cont=enumerate(nums)
        cont=sorted(cont,key=lambda x:x[1])
        for p in range(1,len(cont)):
            if cont[p-1][1]==cont[p][1]:
                if cont[p][0]-cont[p-1][0]<=k:
                    return True
        return False
```
