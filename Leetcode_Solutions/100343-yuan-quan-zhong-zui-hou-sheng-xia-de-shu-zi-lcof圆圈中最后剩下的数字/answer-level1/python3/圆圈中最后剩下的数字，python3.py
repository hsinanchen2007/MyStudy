### 解题思路
将`0`到`n-1`一共`n`个数存到数组里，按照题意逐个删除数组中的元素
最开始起点为为`0`，删除第`m`个数的话，第`m`个数的索引为`inx = (cur + m%len(nums)-1)%len(nums)`
更新起点位置为`inx`，删除数组中索引为`inx`的元素
如果数组长度为1，跳出循环，返回数组中唯一的元素
### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        cur = 0
        nums = [i for i in range(n)]
        while True:
            inx = (cur + m%len(nums)-1)%len(nums)
            cur = inx
            del nums[inx]
            if len(nums)==1:
                break
        return nums[0]

```