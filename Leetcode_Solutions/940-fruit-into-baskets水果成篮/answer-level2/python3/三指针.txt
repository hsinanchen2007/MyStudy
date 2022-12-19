还没进行优化，时间效率80左右。
在滑动窗口的基础上，多了一个middle指针来记录left指针如何跳转。
### 代码

```python3
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        if len(tree) <= 2:
            return len(tree)
        left = 0
        right = 1
        r = 0
        record = [tree[0]]
        while tree[right] == tree[right-1]:
            right += 1
            if right == len(tree):
                return len(tree)
        middle = right
        record.append(tree[right])
        while right < len(tree):
            while right < len(tree) and tree[right] in record:
                if tree[middle] != tree[right]:
                    middle = right
                right += 1
            r = max(r,right-left)
            if right >= len(tree):
                break
            else:
                record = [tree[right-1], tree[right]]
                left = middle
                middle = right
        return r
```