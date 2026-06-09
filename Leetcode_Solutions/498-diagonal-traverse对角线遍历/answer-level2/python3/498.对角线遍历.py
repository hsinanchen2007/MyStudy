执行用时 :140 ms, 在所有 Python3 提交中击败了99.21%的用户

内存消耗 :15.2 MB, 在所有 Python3 提交中击败了92.59%的用户

尴尬脸。

结题思路如下：

1.排除 M=0 or N=0 的情况，此时答案为空。

2.假设给二维数组,行为 row ，列为 col。
```
[
    [1,  2, 3, 4],
    [5,  6, 7, 8],
    [9, 10,11,12],
    [13,14,15,16]
]
```

画个图

![498.png](https://pic.leetcode-cn.com/09708ef3803533dd02960661b8d68c4c35834a2d376f22813adb4544575580af-498.png)


数组有 A、B、C、D 四条边

遍历的方向有两个，上或下

当向上遍历的时候，边界为 A 和 D 

    满足 A 的条件为 row == 0 and col < N-1 

    满足 D 的条件为 col == N-1

当向下遍历的时候，边界为 B 和 C

    满足 B 的条件为 col == 0 and row < M-1

    满足 C 的条件为 row == M-1


然后照着写代码就完事了。
用 for 循环的话，循环次数为M*N
我用 while 循环，出口设置为 row = m-1  and col = N-1

```
class Solution:
    def findDiagonalOrder(self, x) -> bool:
        M = len(x)
        if not M or not len(x[0]): return []
        N = len(x[0])
        row = col = 0
        result = []
        is_up = True
        while True:
            result.append(x[row][col])
            if row == M-1 and col == N-1: return result

            if is_up:
                if row == 0 and col < N-1:
                    col += 1
                    is_up = False
                elif col == N-1:
                    row += 1
                    is_up = False
                else:
                    row -= 1
                    col += 1
            else:
                if col == 0 and row < M-1:
                    row += 1
                    is_up = True
                elif row == M-1:
                    col += 1
                    is_up = True
                else:
                    row += 1
                    col -= 1

        return result
```
