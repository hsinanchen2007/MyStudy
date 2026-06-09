### 解题思路
思路就是齐头并进式的探索，同时构建无重复元素的索引列表

### 代码

```python3
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        i, j = 0, 0
        tempA, tempB = [], []
        ret, min_ = [], float('inf')
        while i < len(list1) and j < len(list2):
            if list1[i] in tempB:
                if min_ > i + tempB.index(list1[i]):
                    min_ = i + tempB.index(list1[i])
                    ret = [list1[i]]
                elif min_ == i + tempB.index(list1[i]):
                    ret.append(list1[i])
            else:
                tempA.append(list1[i])
            if list2[j] in tempA:
                if min_ > j + tempA.index(list2[j]):
                    min_ = j + tempA.index(list2[j])
                    ret = [list2[j]]
                elif min_ == j + tempA.index(list2[j]):
                    ret.append(list2[j])
            else:
                tempB.append(list2[j])
            i, j = i + 1, j + 1
        while i < len(list1):
            if list1[i] in tempB:
                if min_ > i + tempB.index(list1[i]):
                    min_ = i + tempB.index(list1[i])
                    ret = [list1[i]]
                elif min_ == i + tempB.index(list1[i]):
                    ret.append(list1[i])
            else:
                tempA.append(list1[i])
            i += 1
        while j < len(list2):
            if list2[j] in tempA:
                if min_ > j + tempA.index(list2[j]):
                    min_ = j + tempA.index(list2[j])
                    ret = [list2[j]]
                elif min_ == j + tempA.index(list2[j]):
                    ret.append(list2[j])
            else:
                tempB.append(list2[j])
            j += 1

        return ret
            

```