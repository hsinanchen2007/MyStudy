### 解题思路
前缀和的意思就是，对于一个数组，给定区间`[left, right]`之间的和，等于`[0,right]`的和减去`[0,left)`的和。具体的解释如下图。
![SharedScreenshot.jpg](https://pic.leetcode-cn.com/2fe2fe9d3350a93368f29bc2eced9d2034f2bada55b3f26606aafc823ae32185-SharedScreenshot.jpg)
这样，按照

### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # 前缀和
        sum_left = []
        sum_right = 0
        count = 0
        for idx, num in enumerate(nums):
            sum_left.append(sum_right)
            sum_right += num

            if sum_right - k in sum_left:
                count += sum_left.count(sum_right - k)

        return count
        


```