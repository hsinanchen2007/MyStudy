### 解题思路
用current记录还能往前进多少格，每次进一current则为current-1和当前所处位置的值中的较大值。
当current为0时，代表无法前进，返回False。
反之则为True

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        current=0
        for i in range(len(nums)-1):#最后一格不用检测
            current=max(current-1,nums[i])
            if current==0:return False
        return True


```