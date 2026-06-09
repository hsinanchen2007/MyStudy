### 解题思路
双指针i,j，i指向以探索过的最后一个奇数,用j遍历数组,碰到奇数就和i后面的数交换，因为这个数一定是偶数
![屏幕快照 2020-04-04 20.26.40.png](https://pic.leetcode-cn.com/4b7dac35bd4e8edc3ed06ead85b889154f5b3dd2d6520fde0fdedc362d6b328c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-04%2020.26.40.png)

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        i, n = -1, len(nums)    # i指向最后一个奇数
        for j in range(n):  # 用j遍历数组
            if nums[j] % 2 != 0:    # 如果Nums[j]是奇数
                i += 1  # 将j和i后面的数交换
                nums[i], nums[j] = nums[j], nums[i]
        return nums
```