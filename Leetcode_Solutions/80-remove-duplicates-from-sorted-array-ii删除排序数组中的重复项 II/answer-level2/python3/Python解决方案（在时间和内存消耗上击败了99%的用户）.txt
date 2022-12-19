### 解题思路
用一个标识cur记录当前结尾的位置。
如果遍历到的数nums[i]和nums[cur-1]相等。说明nums[i]==nums[cur]==nums[cur-1]。
因此已经连续三个数相等了。nums[i]直接忽略即可。
如果nums[i]和nums[cur-1]不相等。则应将其赋值到cur+1的位置。
遍历结束以后。cur+1就是需要求的新长度。

### python3

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return len(nums)
        cur = 1
        for i in range(2,len(nums)):
            if nums[i] != nums[cur-1]:
                cur+=1
                nums[cur] = nums[i]
        return cur + 1
```

提交结果：
![lt.JPG](https://pic.leetcode-cn.com/f705a37a7e45ea2cdd8c34439cd936b0c4ce542beace85335d3996db62386e26-lt.JPG)
