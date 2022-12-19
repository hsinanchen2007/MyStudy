**思路：**

由题意，我们知道`count`为固定长度为`256`的整数数组，`count[i]`表示整数`i`在样本中出现的次数，要求返回样本的最大值、最小值、平均值、中位数和众数。

- 最大值就是从数组右边往左数第一个不为`0`的数对应的索引；
- 最小值就是从数组左边往右数第一个不为`0`的数对应的索引；
- 平均值就是把所有的索引（数的值）乘以元素值（出现的频次）再求和，得到样本总和，再除以总频次；
- 中位数的计算，从左到右遍历数组，累加每个值出现的频次：
  - 如果频次总和`n`为奇数，中位数等于频次累加第一次大于等于`n//2+1`的索引；
  - 如果频次总和`n`为偶数，中间两个数，一个是频次累加第一次大于等于`n//2`的索引，另一个是频次累加第一次大于等于`n//2+1`的索引；
- 众数就是数组中元素最大值对应的索引。

时间复杂度 $O(1)$

空间复杂度 $O(1)$

**代码：**

```python
class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        n = sum(count)
        left_cnt, right_cnt = 0, 0
        if n % 2 == 0:
            left_cnt, right_cnt = n//2, n//2 + 1
        else:
            left_cnt, right_cnt = n//2 + 1, n//2 + 1
        s, c = 0, 0
        max_cnt, max_cnt_index = 0, 0
        max_cnt_index = 0
        max_num, medium, min_num = 0, 0, -1
        left_flg, right_flg = False, False
        for i in range(256):
            c += count[i]
            if c >= left_cnt and not left_flg:
                medium += i
                left_flg = True
            if c >= right_cnt and not right_flg:
                medium += i
                right_flg = True
            s += count[i] * i
            if count[i] > max_cnt:
                max_cnt = count[i]
                max_cnt_index = i
            if count[i] > 0:
                max_num = i
                if min_num == -1:
                    min_num = i
        return [float(min_num), float(max_num), float(s/n), float(medium/2), float(max_cnt_index)]
```