### 解题思路
利用str()获取每个元素，判断该元素的字符长度是否是偶数就行（对2取余==0）

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # 利用str()获取每个元素，判断该元素的字符长度是否是偶数就行（对2取余==0）
        count =0
        for i in range(len(nums)):
            if len(str(nums[i])) %2 ==0:
                count += 1
        return count
```