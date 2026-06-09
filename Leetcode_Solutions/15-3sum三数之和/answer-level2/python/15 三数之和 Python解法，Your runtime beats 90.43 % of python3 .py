这道题搞了我很久，一直都是超时问题。
解法比较简单，类似C的双指针。
比较耗时的地方，循环的时候，当拿到一个和为0的三个数，需要去重，不要再整个最终结果去重，因为最终结果list非常大，耗时。
在for循环里对单个结果list去重。
详见代码备注。
应该也可以在指针移动的时候判断是否跟上一个相等，相同的话跳过到下一个数字。但这样代码有点搞，没去实现。去重比较方便点。

```
class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = []
        for k in range(len(nums)-2):
            res = [] # 分批存每个数的结果集
            if nums[k] > 0:
                break
            if k >= 1 and nums[k] == nums[k-1]:
                continue
            nums_temp = nums[k:]
            i = 1
            j = len(nums_temp) - 1
            while i < j:
                sum_three = nums_temp[0] + nums_temp[i] + nums_temp[j]
                if sum_three > 0:
                    j -= 1
                elif sum_three < 0:
                    i += 1
                else:
                    threes = [nums_temp[0], nums_temp[i], nums_temp[j]]
                    # 在res里去重，不要再result里判断去重，否则容易超时
                    if not threes in res:
                        res.append(threes)
                    i += 1
                    j -= 1
            result.extend(res)

        return result
```

