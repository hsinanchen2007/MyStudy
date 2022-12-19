# [0...write) 表示已经写完的部分done
# [write...read) 读过，但是超过两次的部分
# [read...n-1] 还没读取的部分
# 只需要比较nums[write - 2] 和 nums[read]是否相等；如果相等，说明nums[write - 2] == nums[write - 1] == nums[read]，已经出现了2次；那么直接pass

```
    def removeDuplicates(self, nums: List[int]) -> int:
        write = 0
        for read in range(len(nums)):
            if write < 2 or nums[read] != nums[write - 2]:
                nums[write] = nums[read]
                write += 1
        return write
```
