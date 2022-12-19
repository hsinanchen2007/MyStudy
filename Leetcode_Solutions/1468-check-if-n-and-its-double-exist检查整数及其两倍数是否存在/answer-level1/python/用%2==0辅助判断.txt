### 解题思路
此处撰写解题思路
如果存在符合条件的情况，其中2倍的数肯定 % 2 == 0，这样就可以遍历其中 % 2 == 0的数字，然后查看 /2 是否仍然存在于数组中，且不是自己（排除0）。

### 代码

```python
class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr_2 = set()
        for i in range(len(arr)):
            item = arr[i]
            if item % 2 == 0:
                item_2 = item / 2
                if item_2 in arr[:i] or item_2 in arr[i + 1:]:
                    return True
        return False
                
```