### 解题思路
两个for循环，注意的点是j是不能等于i的，这点是必须要注意的，其他的倒没什么了；另外要注意是==，不是=，之前写过代码，然后执行失败了原来是自己脑袋蒙圈了哈哈哈


### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for i in range(0,length):
            for j in range(i+1,length):
                if nums[i] +nums[j] ==target:
                    return i,j




```