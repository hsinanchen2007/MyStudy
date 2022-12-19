### 解题思路
思路：用哈希表记录每次出现相同元素的索引值和，返回values最小的key

### 代码

```python3
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {x: list1.index(x) + list2.index(x) for x in set(list1) & set(list2)}
        return [x for x in d if d[x] == min(d.values())]

```