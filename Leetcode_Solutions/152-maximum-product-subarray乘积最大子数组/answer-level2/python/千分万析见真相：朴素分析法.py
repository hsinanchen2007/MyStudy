### 解题思路
首先使用0元素将问题分解为几个子问题。
对于子问题采取如下方法：
1. 统计负数的个数
2. 如果负数是偶数， 那么直接所有数相乘就是子问题的答案
3. 如果负数是奇数，那么 a):计算第一个负数以及前面所有正数的积, b) 计算最后一个负数以及后面所有负数的积， c) 比较两个积，将较大的那个从子问题所有数字的乘积中除去，就得到了子问题答案
而原问题答案是子问题答案中的最大值

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        def get_ans(nums):
            minus_n = 0
            for a in nums:
                if a < 0:
                    minus_n += 1
            
            ans = 1
            for a in nums:
                ans *= a

            if len(nums) == 1:
                return nums[0]
            elif minus_n % 2 == 0:
                return int(ans)
            else:
                start = 1
                end = 1
                for a in nums:
                    start *= a
                    if a < 0:
                        break
                for a in reversed(nums):
                    end *= a
                    if a < 0:
                        break
                print(ans, start, end)
                if start > end:
                    return int(ans/start)
                else:
                    return int(ans/end)
        zero_inds = [ind for ind, a in enumerate(nums) if a==0]
        zero_inds.insert(0, -1)
        zero_inds.append(len(nums))
        ans = []
        if len(zero_inds) > 2:
            ans = [0]
        for a, b in zip(zero_inds[:-1], zero_inds[1:]):
            if a+1 != b:
                ans.append(get_ans(nums[a+1:b]))
        print(zero_inds, ans)
        return max(ans)
```