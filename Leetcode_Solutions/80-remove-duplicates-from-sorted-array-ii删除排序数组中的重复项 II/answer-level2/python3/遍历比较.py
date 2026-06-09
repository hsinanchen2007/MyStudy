- 排序数组，如果第i个元素和第i-2个元素相同，那么说明这个元素的个数大于2，删除即可。

- 注意点：因为是原地删除，所以每一次删除nums的长度会减1，下一次遍历的i不能加1
```
    i = 2
    while i<len(nums):
        if nums[i] == nums[i - 2]:
            nums.pop(i)
        else:
            i += 1
    return len(nums)

```
