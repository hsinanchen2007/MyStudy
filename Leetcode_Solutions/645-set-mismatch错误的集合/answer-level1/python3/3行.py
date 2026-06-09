### 解题思路
见注释

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        # 找到重复的元素
        ans = [k for k,v in dict(collections.Counter(nums)).items() if v == 2]
        # 找到丢失的元素，丢失的元素 = n*(n+1)/2 - (sum(nums) - 重复元素)
        ans.append((len(nums)+1)*len(nums) // 2 - sum(nums) + ans[0])
        return ans

```