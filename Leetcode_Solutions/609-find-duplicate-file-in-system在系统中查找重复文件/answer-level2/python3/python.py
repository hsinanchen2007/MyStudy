### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)
        for path in paths:
            info = path.split()
            for i in range(1, len(info)):
                sub_info = info[i].strip(")").split("(")
                res[sub_info[1]].append(info[0] + "/" + sub_info[0])
        return [l for _, l in res.items() if len(l) > 1]
            

```