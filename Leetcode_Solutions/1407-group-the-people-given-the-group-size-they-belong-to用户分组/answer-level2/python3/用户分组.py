### 解题思路
确定分组中元素相异的个数，依次遍历整个数组，并把对应同一个元素的索引放置在相应数组中，如果该数组的长度超过了该元素的值，则可以利用该元素的值把数组切分成长度为该元素长度的若干个小列表，并以此添加到最终分组中。

### 代码

```python3
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        list1 = list(set(groupSizes))
        list1.sort()
        group = []
        n = max(groupSizes)
        for i in range(len(list1)):
            list2 = []
            for j in range(len(groupSizes)):
                if groupSizes[j] == list1[i]:
                    list2 += [j]
            if len(list2) > list1[i]:
                list3 = list2.copy()
                k = 0
                while(k + list1[i] <= len(list3)):
                    group1 = list3[k:k+list1[i]]
                    group.append(group1)
                    k += list1[i]
            else:
                group.append(list2)
        return group
        
```