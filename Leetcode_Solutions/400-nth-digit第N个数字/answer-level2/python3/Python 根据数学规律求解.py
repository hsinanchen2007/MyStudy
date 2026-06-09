
#### 规律：
##### 1. 根据题意，列出一些小的数，可观察计算得到以下规律：
 - 1-9有9个数，10-99有20*9个数字，100-999有300*9个数字，1000-9999有4000*9个数字
 - 即 9 * pow(10, i - 1) * i， i为数值位数
##### 2. 在对应位数下，数值每增一，需要移动的步长为位数值：
 - 比如个位数中，数值每增一，需要移动一次；十位数中，数值每增一，需要移动两次... 并以此类推
 - 即每增一需要的步长为 step_length = i
##### 3. 可根据以上规律，求出
 1. 对应移动次数nth所在的位数区间
 2. 区间的起始/结束值，以及区间的起始/结束次数
 3. 移动nth次所在的数值
 4. 停留在数值的具体位置
#### 效率：
> Runtime: 8 ms, faster than 96.34% of Python online submissions for Nth Digit.
> Memory Usage: 11.7 MB, less than 54.55% of Python online submissions for Nth Digit.
#### 复杂度分析：
 - 时间复杂度：todo
 - 空间复杂度：$O(1)$
#### 代码：
```Python
# 规律：1-9有9个数，10-99有20*9个数字，100-999有300*9个数字，1000-9999有4000*9个数字
class Solution(object):

    def findNthDigit(self, nth: int) -> int:
        # 所在位数规律：9 * pow(10, i - 1) * i
        i, max_count = 0, 0
        while max_count < nth:
            i += 1
            max_count += i * (9 * 10 ** (i - 1))

        # 起始值对应的次数(nth)
        start_count = max_count - i * (9 * 10 ** (i - 1))

        power = i - 1  # 幂（用于求所在位数）
        start_val = 10 ** power  # 起始值

        step = nth - start_count - 1  # 剩余移动步数
        step_length = i  # 每增一需要的步长
        # offset - 偏移值（从起始值开始）
        # pos - 结果值指向的位数 - 从最高位开始偏移
        offset, pos = divmod(step, step_length)

        curr_val = start_val + offset  # 当前数值 - 起始值 + 偏移值
        # 对应位数的数字，即解
        result = curr_val // 10 ** (power - pos) % 10

        return result

```