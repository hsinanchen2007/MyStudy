```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # 查找k时保持不动的p位数字
        p = 0
        a = 1
        for i in range(n):
            a *= (i + 1)
            if a >= k:
                p = n - i - 1
                break
        # k时不变的数字添加到字符串后面
        num_list = [i + 1 for i in range(n)]
        ans = []
        for i in range(p):
            ans.append(num_list.pop(0))
        # k时变动的数字添加到字符串后面
        for i in range(n-p):
            if k == 1:
                ans.append(num_list.pop(0))
            else:
                m = 1
                for l in range(1, n-p-i):
                    m *= l
                j = (k - 1) // m
                ans.append(num_list.pop(j))
                k %= m
        return ''.join(map(str, ans))
```
