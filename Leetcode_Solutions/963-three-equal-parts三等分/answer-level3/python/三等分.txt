#### 方法一： 将 `1` 的数量三等分

**思路**

如果存在这种分法，那么最终每一部分 `1` 的数量一定是相等的。下面给出的算法也是基于这个思路。

**算法**

设 `S` 为 `A` 中 `1` 的个数，最终每一块 `1` 的数量是相同的，那么每一块都有 `T = S / 3` 个 `1`。

如果 `S` 不能被 `3` 整除，显然不存在这种分法。

可以简单地找到 `A` 中第 `1` 个，第 `T` 个，第 `T+1` 个，第 `2T` 个，第 `2T+1` 个，第 `3T` 个 `1`。这些位置形成了三个区间，`[i1, j1], [i2, j2], [i3, j3]`。（如果只有 `3` 个 `1`，每个区间的大小为 `1`）。

除去这三个区间，可能还有一些后缀 `0`。`0` 的数量由 `j3` 之后有多少 `0` 来决定，`j3` 之后 `0` 的数量为 `z = S.length - j3`。

加上后缀 `0` 之后，第一部分 `[i1, j1]` 就变成了 `[i1, j1+z]`，同样第二部分 `[i2, j2]` 也变成了 `[i2, j2+z]`。

如果这三个区间都合法，那么答案就是 `[j1+z, j2+z+1]`。

```java [solution1-Java]
class Solution {
    public int[] threeEqualParts(int[] A) {
        int[] IMP = new int[]{-1, -1};
        int N = A.length;

        int S = 0;
        for (int x: A) S += x;
        if (S % 3 != 0) return IMP;
        int T = S / 3;
        if (T == 0)
            return new int[]{0, N - 1};

        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
        int su = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 1) {
                su += 1;
                if (su == 1) i1 = i;
                if (su == T) j1 = i;
                if (su == T+1) i2 = i;
                if (su == 2*T) j2 = i;
                if (su == 2*T + 1) i3 = i;
                if (su == 3*T) j3 = i;
            }
        }

        // The array is in the form W [i1, j1] X [i2, j2] Y [i3, j3] Z
        // where [i1, j1] is a block of 1s, etc.
        int[] part1 = Arrays.copyOfRange(A, i1, j1+1);
        int[] part2 = Arrays.copyOfRange(A, i2, j2+1);
        int[] part3 = Arrays.copyOfRange(A, i3, j3+1);

        if (!Arrays.equals(part1, part2)) return IMP;
        if (!Arrays.equals(part1, part3)) return IMP;

        // x, y, z: the number of zeros after part 1, 2, 3
        int x = i2 - j1 - 1;
        int y = i3 - j2 - 1;
        int z = A.length - j3 - 1;

        if (x < z || y < z) return IMP;
        return new int[]{j1+z, j2+z+1};
    }
}
```

```python [solution1-Python]
class Solution(object):
    def threeEqualParts(self, A):
        IMP = [-1, -1]

        S = sum(A)
        if S % 3: return IMP
        T = S / 3
        if T == 0:
            return [0, len(A) - 1]

        breaks = []
        su = 0
        for i, x in enumerate(A):
            if x:
                su += x
                if su in {1, T+1, 2*T+1}:
                    breaks.append(i)
                if su in {T, 2*T, 3*T}:
                    breaks.append(i)

        i1, j1, i2, j2, i3, j3 = breaks

        # The array is in the form W [i1, j1] X [i2, j2] Y [i3, j3] Z
        # where [i1, j1] is a block of 1s, etc.
        if not(A[i1:j1+1] == A[i2:j2+1] == A[i3:j3+1]):
            return [-1,-1]

        # x, y, z: the number of zeros after part 1, 2, 3
        x = i2 - j1 - 1
        y = i3 - j2 - 1
        z = len(A) - j3 - 1

        if x < z or y < z: return IMP
        j1 += z
        j2 += z
        return [j1, j2+1]
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 为 `S` 的长度。

* 空间复杂度： $O(N)$。