### 解题思路
用两个索引l,r遍历数组，如果l--r之间的和>=s，l右移；否则r右移。
注：由于移动时只需要删除一位，添加一位，而且看的是数值的和。因此子数组不需要另外存储，可以减小时间和空间的复杂度。

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l = len(nums)
        if l == 0: return 0
        subsum =nums[0]
        i = 0     #l
        j = 1     #r
        subl = l + 1
        while(i<l):
            if subsum >= s:
                subl = min(subl,j-i)
                subsum -= nums[i]
                i += 1
            else:
                if j==l:
                    break
                subsum += nums[j]
                j += 1
        if subl == l+1:
            return 0
        else:
            return subl

        

```