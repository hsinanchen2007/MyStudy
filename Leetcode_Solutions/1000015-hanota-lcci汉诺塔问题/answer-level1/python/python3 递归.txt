
n = 1 时，直接把盘子从 A 移到 C；
n > 1 时，
先把上面 n - 1 个盘子从 A 移到 B（子问题，递归）；
再将最大的盘子从 A 移到 C；
再将 B 上 n - 1 个盘子从 B 移到 C（子问题，递归）。
```
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        n = len(A)
        if n == 1 :
            C.append(A[0])
            A.pop()
            return
        B.extend(A[1:])
        C.append(A[0])
        A.clear()
        self.hanota(B,A,C)
```
![QQ截图20200401112949.png](https://pic.leetcode-cn.com/0fa67d3c4b743ec7b47b2a20c8a550d00c73a1fc269647fc20c309e3faa444d1-QQ%E6%88%AA%E5%9B%BE20200401112949.png)
