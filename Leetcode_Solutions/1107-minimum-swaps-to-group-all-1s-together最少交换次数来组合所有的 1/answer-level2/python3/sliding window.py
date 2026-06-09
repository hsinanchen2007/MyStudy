### 解题思路
最后所有的1都会被放到一起，那么只要计算出所有1的个数，然后用这么大小的窗口遍历数组，找出一个窗口，里面有最多的1，然后缺少的1个数就是需要的最少交换次数

### 代码

```python3
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        size = data.count(1)
        count = data[:size].count(1)
        ans = size-count
        for i in range(len(data)-size):
            count += data[i+size] - data[i]
            ans = min(ans, size-count)
        return ans
```