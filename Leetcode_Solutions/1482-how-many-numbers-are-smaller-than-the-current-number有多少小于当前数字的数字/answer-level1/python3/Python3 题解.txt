数字是运算效率最高的，所以我把问题转化成了数字计算，用数组中其他数字除于当前数字并向下取整，如果为0，那肯定是小于当前数字，否则就是大于等于当前数字

比如数组nums = [2, 7, 3, 1]
用除法的结果是：
7 // 2 = 3
3 // 2 = 1
1 // 2 = 0

所以对于2来说，只有一个数字比他小。

需要注意的是被除数不能为0，所以需要对当前数字做0条件的判断。

```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        result = []
        for i in nums:
            count = 0
            l = nums.copy()
            l.remove(i)
            for j in l:
                if i == 0:
                    if j < 0:
                        count += 1
                elif j // i == 0:
                    count += 1
            result.append(count)
        return result
```

