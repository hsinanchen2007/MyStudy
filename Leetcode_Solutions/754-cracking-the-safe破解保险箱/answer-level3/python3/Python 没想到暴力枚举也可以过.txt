![image.png](https://pic.leetcode-cn.com/287d7fe47464c6458b6aa997bfb936c5d7dc5d310e7ed4ac585c574c05059469-image.png)


```
'''
暴力枚举可能的字符串，保证长度是n的滑动窗口在字符串上往右滑时候
每次窗口里面的子串都不一样， n位k进制数，总共k**n种，有k**n个窗口
字符串总长度是int(k**n-1) + n
'''

class Solution:

    def dfs(self, cur_pos, max_pos, n, k, path, ans, visited):
        if len(ans) == 1:
            return

        if cur_pos == max_pos:
            ans.append(''.join(path))
            return

        if cur_pos < n-1:
            for val in range(k):
                path.append(str(val))
                self.dfs(cur_pos+1, max_pos, n, k, path, ans, visited)
                path.pop(-1)

                if len(ans) == 1:
                    return
        else:
            for val in range(k):
                path.append(str(val))
                s = ''.join(path[-n:])
                if s in visited:
                    path.pop(-1)
                    continue

                visited.add(s)
                self.dfs(cur_pos+1, max_pos, n, k, path, ans, visited)
                visited.remove(s)
                path.pop(-1)

                if len(ans) == 1:
                    return


    def crackSafe(self, n: int, k: int) -> str:
        ans = []
        self.dfs(0, int(k**n-1) + n, n, k, [], ans, set())

        return ans[0]
```
