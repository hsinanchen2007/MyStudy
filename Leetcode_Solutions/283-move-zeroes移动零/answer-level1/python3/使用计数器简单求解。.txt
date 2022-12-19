### 解题思路
解法思路：1.计算出原数组的0的个数 2. 新建一个数组放入原来数组的非0，再放入count个0 3. 将新数组赋值到原数组上。

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        newList = []
        count = 0
        for i in nums:
            if i == 0:
                count += 1
            else:
                newList.append(i)
        for i in range(count):
            newList.append(0)
        for i in range(len(newList)):
            nums[i] = newList[i]
```