### 解题思路
分两部分：在arr2中的元素和不在arr2中的元素
1. 在arr2中的元素，需要考虑怎么重复：统计每个元素在arr1中出现的次数，然后依照在arr2中的顺序进行重复
2. 不在arr2中的元素，排序后挂到后面就行

### 代码

```python3
from collections import Counter

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        newArr = []  # 新的列表
        dictArr1 = collections.Counter(arr1)  # 先统计arr2中元素在arr1中出现的次数
        for ele in arr2:
            newArr += [ele] * dictArr1[ele] # 每个元素按照arr2中的顺序，按照出现的次数进行重复
            
        arr1Only = []  # 统计只出现在arr1中的元素，并排序
        for ele in arr1:
            if ele not in arr2:
                arr1Only.append(ele) 
        arr1Only = sorted(arr1Only)  

        return newArr + arr1Only  # 合并两部分
```