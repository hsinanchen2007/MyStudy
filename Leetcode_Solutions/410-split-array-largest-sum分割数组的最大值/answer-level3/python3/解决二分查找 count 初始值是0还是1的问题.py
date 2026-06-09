"""
在count初始值是0还是1的问题上,其实0或1均可，count= 0,则可能会少计数一个，count=1则可能多计数一个
故要修改后面左右指针比较时的“=”放置问题，下面代码如下，均通过
"""
```
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
      l,r = max(nums),sum(nums)
      while l < r:
        mid = (l + r) >> 1 
        count,tmp = 0,0 ####count = 0,则可能会少计数一个符合条件的字数组（最后一个子数组可能不计入）
        for num in nums:
          tmp += num
          if tmp > mid:
            tmp = num
            count += 1
            
        if count >= m: ####"="要放在上面，因为“=”的情况也可能实际上多了一个，即mid小了
          l = mid + 1
        else:
          r = mid
      return l
```
```
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
      l,r = max(nums),sum(nums)
      while l < r:
        mid = (l + r) >> 1 
        count,tmp = 1,0####count = 1,则可能会多计数一个符合条件的字数组（最后一个子数组可能计入）
        for num in nums:
          tmp += num
          if tmp > mid:
            tmp = num
            count += 1
            
        if count > m: ####"="要放在下面，因为“=”的情况也可能实际上少了一个，即mid小了
          l = mid + 1
        else:
          r = mid
      return l
```
