基本算法思想是暴力枚举，那么每个点需要和前`n`个构成新的直线，并检查是否和原有的直线重合。那么本题的主要问题有如下几个：

* 直线方程的归一化，即对一条直线上任意两点，求出唯一的直线方程

* 避免计算过程中整数运算溢出

考虑直线方程：

两点式方程： $(x-x_0) / (x_1 - x_0) = (y - y_0) / (y_1 - y_0)$

两点式方程的一般形式：$(x-x_0)(y_1-y_0)=(y-y_0)(x_1-x_0)$

展开为：$(y_1-y_0)x-(y_1-y_0)x_0 = (x_1-x_0)y-(x_1-x_0)y_0$

移动到左边：$(y_1-y_0)x - (x_1-x_0)y + (x_1-x_0)y_0 -(y_1-y_0)x_0 = 0$

展开为：$(y_1-y_0)x - (x_1-x_0)y + (x_1y_0-x_0y_0 -x_0y_1+x_0y_0) = 0$

即：$(y_1-y_0)x - (x_1-x_0)y + (x_1y_0 -x_0y_1) = 0$

令 $A=y_1-y_0, B=x_1-x_0, C=x_1y_0-x_0y_1$ 则得到一般性的直线方程

$Ax-By+C=0$

两边除以 $(y_1-y_0),(x_1-x_0)$的最大公约数 $gdc$ 即得到归一化的一般性直线方程。

进一步归一化：

* 若 $A=0，B=-1$，两边同时乘以 $-1$，统一归一化为 $B=1$
* 若 $A<0$，两边同时乘以 $-1$，统一归一化为 $A > 0$

至此，得到的直线方程可以满足：对于直线上的任意两点，计算出的$(A,B,C)$的值都是一致的。而且很明显，在归一化计算过程中，$A,B,C$ 都有可能超出 Int32 的范围，但是都不会超出 Int64 的范围。

用 $A,B,C$ 作为直线的 `Key` ，将所有可构成的直线保存在一个哈希表 Lines 中，每个条目的值用来记录该直线对应的点的数量，然后就是简单的暴力枚举算法：

1. 首先合并重复的点，得到列表 `points (x, y, count)`
2. 外循环从第 2 个点开始，记为 p0
3. 对之前的每个点 p1
4. 创建一条直线$(p_0, p_1)$，判断是否和已有的直线重叠：
   1. 如果不重叠，则直接加入到直线集中
   2. 如果重叠，则必然还会和其他的点构成已有的直线，因此加入到临时的哈希表暂存
5. 完成 p1 的遍历后将暂存列表中的每条直线的点数添加 p0 的点数

```c#
    public int MaxPoints(int[][] points) {
        // 合并重复的点，并记录每个独立点的数量
        var set = points.Select(t => (x: t[0], y: t[1])).GroupBy(t=>t, (p, t) => (p.x, p.y, count:t.Count())).ToList();
        // 如果只存在不多于两个独立点，显然，一条直线包含了所有的点
        if (set.Count <= 2) return points.Length;
        
        var lines = new Dictionary<(long dx, long dy, long c), int>(points.Length * (points.Length / 2 + 1));
        var tmpLines = new Dictionary<(long dx, long dy, long c), int>(points.Length);

        foreach (var (x0, y0, c0) in set.Skip(1)) {
            tmpLines.Clear();
            foreach (var (x1, y1, c1) in set)  {
                if (x1 == x0 && y1 == y0) break;
                var line = GetLinearEquation(x0, y0, x1, y1);

                if (lines.TryGetValue(line, out var count))
                    tmpLines[line] = count;
                else
                    lines.Add(line, c0 + c1);
            }
            foreach (var line in tmpLines) lines[line.Key] = line.Value + c0;
        }

        return lines.Max(t => t.Value);
    }

    private static (long a, long b, long c) GetLinearEquation(int x0, int y0, int x1, int y1) {
        var dx = (long)x0 - x1;
        var dy = (long)y0 - y1;
        var c = (long) x1 * y0 - (long) x0 * y1;

        if (dx == 0) return (0, 1, c / dy);
        if (dy == 0) return (1, 0, c / dx);

        var gcd = dx;
        var tmp = dy;
        while (tmp != 0) (gcd, tmp) = (tmp, gcd % tmp);
        if (Math.Sign(dx) != Math.Sign(gcd)) gcd = -gcd;
        return (dx / gcd, dy / gcd, c / gcd);
    }
```
