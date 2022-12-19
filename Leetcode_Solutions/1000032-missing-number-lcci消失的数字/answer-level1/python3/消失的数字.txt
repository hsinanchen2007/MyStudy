### 解题思路
方法一和方法二的通过情况如图：
![image.png](https://pic.leetcode-cn.com/9ec9f180f1927ef80408cce6e1ecbadf4efe28c3dc91169408ca75f2ed0a8a50-image.png)


### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        store = [0] * (len(nums) + 1)
        for i in nums:
            store[i] = 1
        
        return store.index(0)


        # 方法2：耗时较长
        # for i in range(len(nums)+1):
        #     if i not in nums:
        #         return i
```