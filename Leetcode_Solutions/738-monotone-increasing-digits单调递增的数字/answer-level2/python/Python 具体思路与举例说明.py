### 思路

将 `N` 从高位往低位遍历，遍历过程中做两件事：

1. 记录遇到的最大值和最大值所在位置，假设分别记为 `max_num` 和 `begin`
2. 比较相邻数字，若遇到后一位数比当前数小时（非递增），退出遍历

此时，我们将 `max_index` 位置的数减去 1，并将 `begin` 位置后的数都置为 9，所得出的数就是我们想要的结果。

### 举例

拿 `N = 332` 举个栗子。

遍历过程：

1. 拿到数字 3，为当前最大值，记录 `max_num = 3`，`begin = 0`；与后一位数比较，`3 == 3`，继续遍历
2. 拿到数字 3，没有大于 `max_num`，因此不更新最大值和最大值所在位置；与后一位数比较发现 `3 > 2`，出现非递增，退出遍历

遍历结束后我们拿到 `begin = 0`，因此我们把 `begin` 位置的数减 1，即把第一位数减去 1，第 1 位后的其他数置 9，得到：`299`。

### 实现

```python [-Python]
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        nums = list(str(N))
        length = len(nums)
        begin = 0
        # N 是否符合条件
        is_result = True
        max_num = float('-inf')
        
        # 从前往后观察
        for i in range(1, length):
            num = int(nums[i])
            pre_num = int(nums[i - 1])
            # 记录最大值
            if pre_num > max_num:
                begin = i - 1
                max_num = pre_num
            if pre_num > num:
                is_result = False
                break
        
        # 如果 N 本身符合条件，直接返回 N
        if is_result:
            return N
        
        # begin 位置减去 1，后面全部替换为 9
        nums[begin] = str(int(nums[begin]) - 1)
        for i in range(begin + 1, length):
            nums[i] = '9'
                    
        return int("".join(nums))
```