很奇怪在测试样例11, 8, 16，我的答案是87，结果是88，一直没能看出哪里写错了，求教
```
class Solution(object):
    def check(self, x, y, k):
        if x < 0 or y < 0:
            return False

        ans = 0
        xx, yy = x, y
        while x:
            if x == 0:
                break
            ans += x % 10
            x = x // 10

        while y:
            if y == 0:
                break
            ans += y % 10
            y = y // 10

        if xx + yy <= k:
            return True
        else:
            return False

    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        cnt = 0
        q = []
        flag = [[0] * n for i in range(m)]
        q.append((0, 0))
        flag[0][0] = 1
        cnt += 1

        while not len(q)==0:
            frontNode = q.pop(0)
            curx, cury = frontNode

            for x, y in (curx, cury + 1), (curx, cury - 1), (curx - 1, cury), (curx + 1, cury):
                if 0 <= x < m and 0 <= y < n:
                    if flag[x][y] == 0 and self.check(x, y, k):
                        cnt += 1
                        q.append((x, y))
                        flag[x][y] = 1

        return cnt


ans = Solution().movingCount(
)
print(ans)

```
