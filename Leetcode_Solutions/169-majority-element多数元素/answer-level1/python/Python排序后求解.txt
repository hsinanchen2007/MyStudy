### 解题思路
首先，尝试直接双循环超时了。
最终方案：先排个序，然后一个循环找到“突变点”，
如果突变点之前的数字不达标则放弃这个数字，直到寻找到“多数元素”。
不要忘记n=1的情况。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if n <= 1:
            return nums[0]
        n_2 = n / 2
        flag = 1
        for a in range(0, n - 1):
            if nums[a] == nums[a + 1]:
                flag += 1
                if flag - n_2 > 0:
                    return nums[a]
            else:
                flag = 1



```