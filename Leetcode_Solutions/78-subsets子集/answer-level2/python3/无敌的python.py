### 解题思路
运用迭代和列表推导式无敌
![image.png](https://pic.leetcode-cn.com/88d731eaa7e022fe7ab91463426a89f1f0aa441bfb347aef5d35e4e997ad9f2d-image.png)


### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        arr = [[]]

        for i in nums:
            arr+=[j+[i] for j in arr]
        return arr
```