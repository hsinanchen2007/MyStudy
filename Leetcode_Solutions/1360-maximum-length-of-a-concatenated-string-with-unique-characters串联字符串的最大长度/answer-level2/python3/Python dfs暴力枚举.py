![image.png](https://pic.leetcode-cn.com/45766755f964328bd698267d9ca704b2d094ace9d102ba9ec0d2fa1f675b0442-image.png)


```

from typing import List
from collections import Counter
class Solution:

    def isSingleChar(self, s: str):
        return Counter(s).most_common()[0][1] == 1

    def dfs(self, arr, cur_pos, path, ans):
        if not self.isSingleChar(arr[cur_pos]):
            ans[0] = max(ans[0], len(path))
            return

        if len(set(arr[cur_pos]) & set(path)) != 0:
            ans[0] = max(ans[0], len(path))
            return

        if cur_pos == len(arr) - 1:
            ans[0] = max(ans[0], len(path) + len(arr[cur_pos]))
            return

        for next in range(cur_pos+1, len(arr)):
            self.dfs(arr, next, path+arr[cur_pos], ans)


    def maxLength(self, arr: List[str]) -> int:
        ans = [0]
        n = len(arr)

        for start in range(n):
            self.dfs(arr, start, '', ans)

        return ans[0]
```
