先看代码:
```
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        rows = [0] * n
        cols = [0] * m
        for r, c in indices:
            rows[r] ^= 1
            cols[c] ^= 1
        sr = sum(rows)
        sc = sum(cols)
        return sr * (m - sc) + (n - sr) * sc
```
1 因为只统计奇数的个数, 因此, 求个数的时候, 只关心是不是奇数即可. 可以利用1或0表示奇数还是偶数, 如果是奇数, 那么值为1, 如果是偶数, 值为0.
2 可以通过num ^= 1来切换0, 1, 即"0 ^ 1 -> 1", "1 ^ 1 -> 0"
3 "sr = sum(rows)"用来统计奇数行数的个数, 那么偶数行的个数为"n - sr". 关于奇数列, 偶数列类似.
4 奇数行与偶数列相交或者偶数行与奇数列相交才能构成奇数的元素.