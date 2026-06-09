![image.png](https://pic.leetcode-cn.com/51df68ed4d84e53fb2157f6c990e612723b2d114db6b13699fa8c2dfc4811b2e-image.png)


```
from typing import List

class Solution:
    #  递归生成字符串
    def solve(self, buf, cur_pos, groups, group_idx, path, ans):
        if cur_pos == len(buf):
            ans.append(''.join(path))
            return

        if buf[cur_pos] != '*':
            path.append(buf[cur_pos])
            self.solve(buf, cur_pos+1, groups, group_idx, path, ans)
            path.pop(-1)
        else:
            for ch in groups[group_idx]:
                path.append(ch)
                self.solve(buf, cur_pos+1, groups, group_idx+1, path, ans)
                path.pop(-1)

    def expand(self, S: str) -> List[str]:
        groups = []
        flag = [0 for _ in range(len(S))]

        start_pos = 0
        while True:
            idx1 = S.find('{', start_pos)
            if idx1 == -1:
                break

            idx2 = S.find('}', idx1+1)
            groups.append(sorted(S[idx1+1: idx2].split(',')))
            flag[idx1: idx2+1] = range(1, idx2-idx1+2)

            start_pos = idx2 + 1

        buf = []
        for i in range(len(S)):
            if flag[i] == 0:
                buf.append(S[i])
            elif flag[i] == 1:
                buf.append('*')

        ans = []
        self.solve(buf, 0, groups, 0, [], ans)
        return ans
```
