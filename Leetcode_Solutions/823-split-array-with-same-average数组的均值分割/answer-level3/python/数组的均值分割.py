#### 方法一：折半搜索

假设我们在数组 `B` 中放了 `K` 个数，数组 `C` 中放了 `N - K` 个数，它们的平均值相等，即 `sum(B) / K = sum(C) / (N - K)`，那么有

```
sum(B) * (N - K) = sum(C) * K
==> sum(B) * N = (sum(B) + sum(C)) * K
==> sum(B) / K = (sum(B) + sum(C)) / N
==> sum(B) / K = sum(A) / N
```

即 `B` 的平均值与 `A` 的平均值相等。因此我们可以将 `A` 中的每个元素减去它们的平均值，这样 `A` 的平均值变为 `0`。此时我们的问题变成：找出若干个元素组成集合 `B`，这些元素的和为 `0`。

一个容易想到的思路是，`N` 个元素中取出若干个有 `2^N` 种方法（即每个元素取或不取），我们依次判断每种方法选出的元素之和是否为 `0`。但题目中的 `N` 可以达到 `30`，`2^N` 会非常大。因此我们考虑将数组平均分成两部分 `A0` 和 `A1`，它们均含有 `N/2` 个元素（不失一般性，这里假设 `N` 为偶数。如果 `N` 为奇数，在 `A0` 中多放一个元素即可），此时这两个数组分别有 `2^(N/2)` 种选择的方法。设 `A0` 中所有选择的方法得到的元素之和的集合为 `left`，`A1` 中所有选择的方法得到的元素之和的集合为 `right`，那么我们只需要在 `left` 中找出一个 `x`，使得 `right` 中包含 `-x`，那么就找到了一种和为 `0` 的方法。需要注意的是，我们不能同时选择 `A0` 和 `A1` 中的所有元素，这样 `C` 就为空了。

此外，“将 `A` 中每个元素减去它们的平均值” 这一步会引入浮点数，可能会导致判断的时候出现误差。一种解决方案是使用分数代替浮点数，但这样代码编写起来较为麻烦。更好的解决方案是先将 `A` 中的每个元素乘以 `A` 的长度，这样它们的平均值一定为整数。

```Java [sol1]
import java.awt.Point;

class Solution {
    public boolean splitArraySameAverage(int[] A) {
        int N = A.length;
        int S = 0;
        for (int x: A) S += x;
        if (N == 1) return false;

        int g = gcd(S, N);
        Point mu = new Point(-(S/g), N/g);
        // A[i] -> fracAdd(A[i], mu)
        List<Point> A2 = new ArrayList();
        for (int x: A)
            A2.add(fracAdd(new Point(x, 1), mu));

        Set<Point> left = new HashSet();
        left.add(A2.get(0));
        for (int i = 1; i < N/2; ++i) {
            Set<Point> left2 = new HashSet();
            Point z = A2.get(i);
            left2.add(z);
            for (Point p: left) {
                left2.add(p);
                left2.add(fracAdd(p, z));
            }
            left = left2;
        }

        if (left.contains(new Point(0, 1))) return true;

        Set<Point> right = new HashSet();
        right.add(A2.get(N-1));
        for (int i = N/2; i < N-1; ++i) {
            Set<Point> right2 = new HashSet();
            Point z = A2.get(i);
            right2.add(z);
            for (Point p: right) {
                right2.add(p);
                right2.add(fracAdd(p, z));
            }
            right = right2;
        }

        if (right.contains(new Point(0, 1))) return true;

        Point sleft = new Point(0, 1);
        for (int i = 0; i < N/2; ++i)
            sleft = fracAdd(sleft, A2.get(i));

        Point sright = new Point(0, 1);
        for (int i = N/2; i < N; ++i)
            sright = fracAdd(sright, A2.get(i));

        for (Point ha: left) {
            Point ha2 = new Point(-ha.x, ha.y);
            if (right.contains(ha2) && (!ha.equals(sleft) || !ha2.equals(sright)))
                return true;
        }
        return false;
    }

    public Point fracAdd(Point A, Point B) {
        int numer = A.x * B.y + B.x * A.y;
        int denom = A.y * B.y;
        int g = gcd(numer, denom);
        numer /= g;
        denom /= g;

        if (denom < 0) {
            numer *= -1;
            denom *= -1;
        }

        return new Point(numer, denom);
    }

    public int gcd(int a, int b) {
       if (b==0) return a;
       return gcd(b, a%b);
    }
}
```

```Python [sol1]
class Solution(object):
    def splitArraySameAverage(self, A):
        from fractions import Fraction
        N = len(A)
        S = sum(A)
        A = [z - Fraction(S, N) for z in A]

        if N == 1: return False

        #Want zero subset sum
        left = {A[0]}
        for i in xrange(1, N/2):
            left = {z + A[i] for z in left} | left | {A[i]}
        if 0 in left: return True

        right = {A[-1]}
        for i in xrange(N/2, N-1):
            right = {z + A[i] for z in right} | right | {A[i]}
        if 0 in right: return True

        sleft = sum(A[i] for i in xrange(N/2))
        sright = sum(A[i] for i in xrange(N/2, N))

        return any(-ha in right and (ha, -ha) != (sleft, sright) for ha in left)
```

**复杂度分析**

* 时间复杂度：$O(2^{N/2})$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(2^{N/2})$。