### 解题思路
一次通过，双百，好激动。

思路是：定义一个value为列表的字典，然后遍历输入，以每个规模为key，组员序号为value list的元素，当value list的size达到组规模的时候，就把这个list添加到结果ans中。

### 代码

```python3
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans = []
        hash_table = collections.defaultdict(list)
        for i in range(len(groupSizes)):
            hash_talble[groupSizes[i]].append(i)
            if len(hash_talble[groupSizes[i]]) == groupSizes[i]:
                ans.append(hash_talble[groupSizes[i]])
                hash_talble[groupSizes[i]] = []
        return ans


```