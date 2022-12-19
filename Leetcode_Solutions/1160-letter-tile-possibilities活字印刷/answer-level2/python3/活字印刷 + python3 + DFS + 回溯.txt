####  方法1：DFS + 回溯
**代码：**

```python []
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        # 对于任意一个字母都有选和不选两个选项；
        # 前面的字母可以后面出现；
        # 只需要序列数目，序列不能重复
        # 这是一个数学问题？这里考虑用DFS+回溯
        letters = [i for i in tiles]
        n = len(letters)
        letters.sort()
        self.count = 0

        def find(visited):
            for i in range(n):
                if i in visited:
                    continue
                if i > 0 and letters[i] == letters[i - 1] and i - 1 not in visited:
                    continue
                visited.add(i)
                self.count += 1
                find(visited)
                visited.remove(i)

        find(set())
        return self.count
```