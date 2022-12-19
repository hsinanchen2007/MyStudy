### 解题思路
- maxp 表示最远可达的位置
- 从头到尾扫描每个位置 j
    - 如果 j <= maxp，说明可达，根据跳跃长度更新 maxp
    - 如果 j > maxp, 说明不可达，则后续位置都不可达，结束扫描
- 扫描结束后，若 maxp >= n-1，说明最后位置可达，否则不可达

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
        思路：
            maxp 表示最远可达的位置
            从头到尾扫描每个位置 j
                如果 j <= maxp，说明可达，根据跳跃长度更新 maxp
                如果 j > maxp, 说明不可达，则后续位置都不可达，结束扫描
            扫描结束后，若 maxp >= n-1，说明最后位置可达，否则不可达
        '''
        n = len(nums)
        maxp = 0
        for j in range(n):
            if j <= maxp:
                maxp = max(maxp, j+nums[j])
            else:
                break
        if maxp >= n-1:
            return True
        else:
            return False

```