### 解题思路
- 犯了一个错误 就是把target和mid的比较 忘记加nums[]了
  然后每次都返回-1 烦死我了哈哈
- 然后记得l和r都要挪一位 而不是原地不动
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left=0
        right=len(nums)-1
        while target >=nums[left] and target <=nums[right] :
            mid=(left+right)//2
            if target == nums[mid] :
                return mid
            elif target > nums[mid]:
                left=mid+1
            else :
                right=mid-1
        return -1
```