### 解题思路
![image.png](https://pic.leetcode-cn.com/251b3153c54328a4fff47c13e610a770500f3df92ea91a3b42c06666075fd7d6-image.png)
- 利用enumerate()函数进行判断
- 该函数返回元素索引值+元素值
- 如果当前元素值value*2 也存在在数组中，并且符合条件的元素值的索引不等于当前值的索引
- 即可返回True
### 代码

```python3
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        for index, value in enumerate(arr):
            if value*2 in arr and index != arr.index(value*2):
                return True
        
        return False
```