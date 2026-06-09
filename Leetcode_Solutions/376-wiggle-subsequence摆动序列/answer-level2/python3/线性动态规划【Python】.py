### 解题思路
线性动态规划
    状态：每当我们选择一个元素作为摆动序列的一部分时，这个元素要么是上升的，要么是下降的，这取决于前一个元素的大小。
    转移函数见代码

### 代码

```python3
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        """
        线性动态规划
        状态：每当我们选择一个元素作为摆动序列的一部分时，这个元素要么是上升的，要么是下降的，这取决于前一个元素的大小。
        :param nums:
        :return:
        """
        len_nums = len(nums)
        if len_nums < 2:
            return len_nums
        up_arr = [0] * len_nums  # 目前为止最长的以第i个元素结尾的上升摆动序列的长度
        down_arr = [0] * len_nums  # 目前为止最长的以第i个元素结尾的下降摆动序列的长度
        up_arr[0] = down_arr[0] = 1
        for i in range(1, len_nums):
            if nums[i] > nums[i - 1]:
                up_arr[i] = max(down_arr[i - 1] + 1, up_arr[i - 1])
                down_arr[i] = down_arr[i - 1]
            elif nums[i] < nums[i - 1]:
                down_arr[i] = max(up_arr[i - 1] + 1, down_arr[i - 1])
                up_arr[i] = up_arr[i - 1]
            else:
                up_arr[i] = up_arr[i - 1]
                down_arr[i] = down_arr[i - 1]
        return max(up_arr[-1], down_arr[-1])
```