### 解题思路
首先对于前一个题目即消失的一个数字的问题，我们可以通过数学方法求1~N的和然后减去整个数组中的值，那么消失的两个数字仍然可以用这种思路做，我们首先计算1~N的和sum_1（这里N的值为length + 1），然后再计算出nums的和sum_2，两个和相减就可以得到缺失的两个数字的和，由于两个数不同，所以如果差是temp，那么一定有一个数 <= temp // 2，而另一个数 > temp，这样就把消失的两个数问题转换为消失的一个数问题。

### 代码

```python
class Solution(object):
    def missingTwo(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def get_sum(m, n):
            return (m + n) * (n - m + 1) // 2
        length = len(nums)
        sum_1 = get_sum(1, length + 2)
        sum_2 = sum(nums)
        mid = (sum_1 - sum_2) // 2
        temp_1, temp_2 = get_sum(1, mid), get_sum(mid + 1, length + 2)
        for num in nums:
            if num <= mid:
                temp_1 -= num
            else:
                temp_2 -= num

        return [temp_1, temp_2]
```