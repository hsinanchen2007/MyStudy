### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findSwapValues(self, array1, array2):
        """
        :type array1: List[int]
        :type array2: List[int]
        :rtype: List[int]
        """
        set_1, set_2 = list(set(array1)), list(set(array2))
        sum_1, sum_2 = sum(array1), sum(array2)
        for i in range(len(set_1)):
            for j in range(len(set_2)):
                if sum_1-set_1[i]+set_2[j] == sum_2-set_2[j]+set_1[i]:
                    return [set_1[i], set_2[j]]
        return []
```