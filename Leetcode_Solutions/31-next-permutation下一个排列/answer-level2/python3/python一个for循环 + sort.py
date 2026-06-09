# 方法一：sort()  耗时40ms
```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1, 0, -1):
            if nums[i] <= nums[i-1]:  # 寻找第一对 nums[i] > nums[i-1]
                if i == 1:  # 处理升序列表
                    nums.reverse()
                    break
                continue
            else:  # 找到第一对 nums[i] > nums[i-1]时
                temp = nums[i-1]
                temp_min = min([x for x in nums[i:] if x > nums[i-1]])

                nums[i-1] = temp_min  # 交换
                nums[i+nums[i:].index(temp_min)] = temp 
                # 对nums[i:]进行排序
                x = nums[i:]
                x.sort()
                for j in range(len(x)):
                    nums[i+j] = x[j]
                break
```
# 方法二：冒泡 耗时56ms

```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1, 0, -1):
            if nums[i] <= nums[i-1]:  # 寻找第一对 nums[i] > nums[i-1]
                if i == 1:  # 处理升序列表
                    nums.reverse()
                    break
                continue
            else:  # 找到第一对 nums[i] > nums[i-1]时
                temp = nums[i-1]
                temp_min = min([x for x in nums[i:] if x > nums[i-1]])

                nums[i-1] = temp_min  # 交换
                nums[i+nums[i:].index(temp_min)] = temp 
                # 对nums[i:]进行排序
                for t in range(i, len(nums)-1):  # 冒泡
                     flag = True
                     for j in range(len(nums)-1, t, -1):
                         if nums[j] < nums[j-1]:
                             flag = False
                             temp = nums[j]
                             nums[j] = nums[j-1]
                             nums[j-1] = temp
                     if flag:
                         break
                break

```

