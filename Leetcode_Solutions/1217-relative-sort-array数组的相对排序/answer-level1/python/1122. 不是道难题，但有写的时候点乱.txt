### 解题思路
1. 统计arr1中各个值出现的个数
2. 先按照arr2中的顺序，将这些在arr2中出现的数值依次排好，记得清空已经排好的数值，为后面统计没出现在arr2中的数值做准备
3. 排列剩下所有没有出现在arr2中的数值

### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # 统计arr1中各个值出现的个数。
        arr1_dict = {}
        for item in arr1:
            if item in arr1_dict.keys():
                arr1_dict[item] += 1
            else:
                arr1_dict[item] = 1

        # 先按照arr2中的顺序，将这些在arr2中出现的数值依次排好，记得清空已经排好的数值，为后面统计没出现在arr2中的数值做准备
        new_list = []
        for item in arr2:
            new_list += arr1_dict[item] * [item]
            arr1_dict[item] = 0

        # 排列剩下所有没有出现在arr2中的数值
        remain_nums = []
        for item in arr1_dict.keys():
            if arr1_dict[item] != 0: # 不为0的即为剩下的数值
                remain_nums += arr1_dict[item] * [item]   

        new_list = new_list + sorted(remain_nums)
        return new_list
```