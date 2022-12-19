### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        w = 0 # 写指针
        r = 1 # 读指针
            """
            w r
            ↓ ↓
            0 1 1 2 3
            """ 
        while r < len(nums):
            if nums[w] == nums[r]: # 相同读取下一个
                r+=1
            else:    # 不同的话,写指针后移至写入位置->赋值->读指针后移一位
                w+=1
                nums[w]=nums[r]
                r+=1

        return w+1  # 长度为index + 1
```