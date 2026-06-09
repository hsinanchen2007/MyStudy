### 解题思路
很恐怖，思路不清楚会很混乱。主要是要记录和更新起始位置

### 代码

```python3
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        if not tree:
            return 0
        i = 0
        j = 1
        mm = 0
        L = len(tree)
        found = [tree[0]]
        tmp = 0
        while j < L:
            if tree[j] in found:
                if tree[j-1] != tree[j]:
                    tmp = j
                j += 1
                continue
            elif len(found) < 2:
                found.append(tree[j])
                tmp = j
                j += 1
            else:
                mm = max(j-i, mm)
                i = tmp
                tmp = j
                found = [tree[i], tree[j]]
                j += 1
        return max(j - i, mm)













```