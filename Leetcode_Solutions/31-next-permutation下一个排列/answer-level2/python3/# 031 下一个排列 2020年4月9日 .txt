### 解题思路
1.降序数组是不存在下一个排列的
2.从后向前找到非降序分界线a[i] < a[i+1], 之后的操作只与a[i:]有关
3.在a[i+1:]从后向前找到可以替换a[i]的a[j]
4.对a[i+1:]做逆序，使a[i+1]为最小排列

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 获取下一个排列
        """
        1.降序数组是不存在下一个排列的
        2.从后向前找到非降序分界线a[i] < a[i+1], 之后的操作只与a[i:]有关
        3.在a[i+1:]从后向前找到可以替换a[i]的a[j]
        4.对a[i+1:]做逆序
        """
        lens = len(nums)
        j = lens-1
        for i in range(lens-2, -1, -1):
            if nums[i] >= nums[j]:
                j = i
            else:
                break
        if j != 0:
            for k in range(lens-1, i, -1):
                if nums[k] > nums[i]:
                    nums[k], nums[i] = nums[i], nums[k]
                    break
        nums[j:] = nums[j:][::-1]

            



        
```