### 解题思路
1.输入数组有可能为空数组
2.定义了个标志位，每交换一次往后移动一位
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        lens = 0
        tmp = nums[lens]
        for i in range(len(nums)-1):
            if tmp != nums[i+1] and nums[i] == tmp:  # 交换
                nums[lens+1] = nums[i+1]
                tmp = nums[i+1]
                lens+=1
        return lens+1
```