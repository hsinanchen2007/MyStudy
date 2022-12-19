>+ modified_cnt 用于记录修改数组的次数
>+ 遍历数组：当一个数nums[i]小于前一个数nums[i-1]时：
>>+ 优先查看nums[i-1]能否被修改以符合非递减（如果i>=2且nums[i-2] <= nums[i],那么将nums[i-1]修改为nums[i]的值；如果i < 2）也将nums[i-1]修改为nums[i]的值；
>>+ 如果修改nums[i-1]行不通，则修改nums[i]；
>>+ 当modified_cnt 大于0时，跳出循环

```python3
def checkPossibility(self, nums: List[int]) -> bool:
        modified_cnt = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                if modified_cnt:
                    return False
                else:
                    if i - 2 >= 0:
                        if nums[i-2] <= nums[i]:
                            nums[i-1] = nums[i]
                        else:
                            nums[i] = nums[i-1]
                    else:
                        nums[i-1] = nums[i]
                    modified_cnt += 1
        return True
```
