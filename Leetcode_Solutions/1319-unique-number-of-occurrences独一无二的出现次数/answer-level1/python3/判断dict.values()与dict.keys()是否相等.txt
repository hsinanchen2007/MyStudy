### 解题思路
1. 用字典记录下所有出现的次数
2. 如果 存在的所有元素的个数 == set(每个元素对应的出现次数)，则说明没有重复。

### 代码

```python3
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        new_dic = {}
        for item in arr:
            if item in new_dic.keys():
                new_dic[item] += 1
            else:
                new_dic[item] = 1

        return len(new_dic.keys()) == len(set(new_dic.values()))

```