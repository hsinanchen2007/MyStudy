### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
      # if k == 0 or len(nums) == 1:
      #   return
      i,j,count,n = 0,0,0,len(nums)#count代表次数，k为当前要交换的指针
      tmp = nums[j]
      while count < n:
        j = (j+k) % n
        tmp,nums[j] = nums[j],tmp
        if j == i:
          i = (i + 1) % n #这个值得注意，就算是+1也要取余，否则可能会越界
          j = i
          tmp = nums[j]
        count += 1
```