### 解题思路
建立一个索引指针，若当前指针与index中值索引值不同时，则将nums中当前位置中的值插入到临时列表的相应位置中，否者直接将当前nums中的值直接追加到临时列表中。

### 代码

```python3
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target =[]
        i = 0
        l =len(index)
        while i < l:
            if i != index[i]:
                target.insert(index[i],nums[i])
            else:
                target +=[nums[i]]
            i +=1
        return target

```