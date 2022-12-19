### 解题思路
专门找的贪心算法的题目来刷，所以思路也比较清晰。
寻找局部最优解。
既然是看能不能顺利到达最后一个点，我就从倒数第二点开始看他能不能到。
能到的话ok_index就设置为对应的那个点，然后不断往前。
每个位置的大小至少要大于等于ok_index - i。
最后只需要判断ok_index是否为0即可。
个人觉得还是很不错的解题方法

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        len1 = len(nums)
        ok_index = len1 - 1
        for i in range(len1- 2,-1,-1):
            if nums[i] >= ok_index - i:
                ok_index = i
                continue
        if ok_index != 0:
            return False
        return True
```