1、先排序，list.sort是在原来的list进行修改，而sorted是排序后创建一个新的list,注意两者的区别
2、直接检索即可
```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        return nums[k-1]
```
