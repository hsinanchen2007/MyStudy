### 解题思路
先计算出数组中0的个数，再循环将0放到最后。这里循环条件是数组长度减0的个数，如果元素为0，那就将0放到后面，如果不为0就将循环计数加1

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n=nums.count(0)
        i=0
        while i<(len(nums)-n):
            if nums[i]==0:
                nums.pop(i)
                nums.append(0)
            else:
                i+=1
```