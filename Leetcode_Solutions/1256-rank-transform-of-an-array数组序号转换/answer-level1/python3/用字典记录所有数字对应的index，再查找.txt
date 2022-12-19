### 解题思路
1. 用字典记录所有的数字与其对应的index，记得数字要set一下，保证没有重复，这样相同的数字才能有相同的index
2. arr中的元素逐一到字典中查找index，返回列表

tips：
enumerate(sequence, [start=0]) 中start可以指定起始的index，可从任意数字开始计起。
### 代码

```
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sorted_arr = sorted(set(arr))
        temp = {}
        for idx, num in enumerate(sorted_arr, 1):
            temp[num] = idx
        return [temp[i] for i in arr]

```