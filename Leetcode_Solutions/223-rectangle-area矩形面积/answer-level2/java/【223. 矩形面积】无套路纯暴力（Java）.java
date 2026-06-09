## 思路

我们的思路是分别算出两个矩阵的面积，然后减去两个矩阵相交的面积。

两个矩阵面积比较简单。而关于求解相交矩阵的面积，我们需要知道相交矩阵的左右上下边界：

- lx 表示重叠区域的左边界的x值
- rx 表示重叠区域的右边界的x值
- ty 表示重叠区域的上边界的y值
- by 表示重叠区域的下边界的y值

我们仍需要考虑如果矩阵不重叠的情况：

- E > C
- F > D
- G < A
- H < B

总之：

- 如果矩阵不相交，我们返回两个矩阵的和
- 否则我们返回两个矩阵的和减去相交的面积

## 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int lx = Math.max(A, E);
        int by = Math.max(B, F);
        int rx = Math.min(C, G);
        int ty = Math.min(D, H);

        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        if (E > C || F > D || G < A || H < B) {
            return area1 + area2;
        }

        return area1 + area2 - (rx - lx) * (ty - by);
    }
}
```



**复杂度分析**
- 时间复杂度：$O(1)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
