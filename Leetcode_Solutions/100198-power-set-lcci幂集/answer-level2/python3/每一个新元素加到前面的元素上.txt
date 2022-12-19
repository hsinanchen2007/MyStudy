### 解题思路
![code.PNG](https://pic.leetcode-cn.com/e288c331b2fb4e91aaa28c7376cc2c70d1804486448dc15bf148ae5ba8882756-code.PNG)
先在result列表中将入一个空子集
然后遍历nums每一个元素，将元素与result中的每个元素结合加到result中
直到nums遍历完

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        result.append([])
        for i in nums:
            l = len(result)
            j = 0
            while j < l:
                result.append(result[j]+[i])
                j += 1
        return result
```