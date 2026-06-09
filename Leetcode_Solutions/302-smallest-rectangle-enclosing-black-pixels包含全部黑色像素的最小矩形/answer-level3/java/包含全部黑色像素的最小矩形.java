#### 方法 1：简单的线性查找

**想法**

遍历所有的像素点，记录黑色像素坐标的最大和最小值。

**算法**

我们记录矩形的四个边界 `left`, `right`， `top` 和 `bottom`。注意到 `left` 和 `top` 是包括在范围以内的而 `right` 和 `bottom` 不包括。我们遍历所有像素并分别更新四个边界。

流程如下：

* 初始化 `left`，`right`，`top` 和 `bottom`
* 遍历所有的坐标 `(x, y)`
  * 如果 `image[x][y]` 是黑色的
    * `left = min(left, x)`
    * `right = max(right, x + 1)`
    * `top = min(top, y)`
    * `bottom = max(bottom, y + 1)`
* 返回 `(right - left) * (bottom - top)`

```java []
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int top = x, bottom = x;
        int left = y, right = y;
        for (x = 0; x < image.length; ++x) {
            for (y = 0; y < image[0].length; ++y) {
                if (image[x][y] == '1') {
                    top = Math.min(top, x);
                    bottom = Math.max(bottom, x + 1);
                    left = Math.min(left, y);
                    right = Math.max(right, y + 1);
                }
            }
        }
        return (right - left) * (bottom - top);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(mn)$ 。 $m$ 和 $n$ 是图片的高和宽。

* 空间复杂度： $O(1)$ 。我们只需要保存 4 个边界。

**评价**
* 也许我们可以提前终止来优化这个算法。但是这不改变渐进表现。
* 这个简单的方法当然不是本题的最优解法。但是它给了你一个很好的切入点。大多数时候一个好的解法来源于重复尝试简单的解法突然产生的灵感。同时这个简单的解法也设置了一个时间复杂度和空间复杂度的基准线，以便比较其他方法的好坏。

#### 方法 2： DFS 或者 BFS

**想法**

找到所有彼此连接的黑色像素并更新边界。

**算法**

简单方法没有使用所有黑色像素是连接在一起的且一个黑色像素的坐标会被给出这一条件。

一个简单的利用此条件的办法是从这个像素开始穷尽搜索。由于所有黑色像素是连接在一起的， DFS 或者 BFS 会从给定的这一黑色像素开始将它们全部访问到。这个想法与 [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) 类似。与该题有很多座岛屿不同的地方在于，此题只有一座岛屿，且我们知道这个岛屿的一个像素。

```java []
public class Solution {
    private int top, bottom, left, right;
    public int minArea(char[][] image, int x, int y) {
        if(image.length == 0 || image[0].length == 0) return 0;
        top = bottom = x;
        left = right = y;
        dfs(image, x, y);
        return (right - left) * (bottom - top);
    }
    private void dfs(char[][] image, int x, int y){
        if(x < 0 || y < 0 || x >= image.length || y >= image[0].length ||
          image[x][y] == '0')
            return;
        image[x][y] = '0'; // mark visited black pixel as white
        top = Math.min(top, x);
        bottom = Math.max(bottom, x + 1);
        left = Math.min(left, y);
        right = Math.max(right, y + 1);
        dfs(image, x + 1, y);
        dfs(image, x - 1, y);
        dfs(image, x, y - 1);
        dfs(image, x, y + 1);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(E) = O(B) = O(mn)$ 。

    这里 $E$ 是遍历的图中边的数目。 $B$ 是黑色像素的数目。因为每个像素最多有 4 条边，所以 $O(E) = O(B)$ 。最坏情况下 $O(B) = O(mn)$ 。

* 空间复杂度： $O(V) = O(B) = O(mn)$ 。

    空间复杂度是 $O(V)$ ，其中 $V$ 是遍历的图中节点的数目。在这个问题里， $O(V) = O(B)$ 。同样地，最坏情况下 $O(B) = O(mn)$ 。

**评论**

尽管在 $B$ 比 $mn$ 小的时候，这个方法比最简单的搜索要更优。但当 $B$ 与 $mn$ 接近时，它的渐进时间复杂度与方法 1 相同。同时这个方法空间开销更大。

#### 方法 3：二分查找

**想法**

把二维图形投影到一维数组，并使用二分查找的方法来找边界。

**算法**
![image.png](https://pic.leetcode-cn.com/b3ec47608d96e5d78bc1db95ee71632faf26bf5ec5cfc2911868de0cae5c241f-image.png){:width="500px"}
{:align="center"}

*Figure 1. Illustration of image projection.
{:align="center"}

假设我们有一个图 1 所示的 $10 \times 11$ 的图，我们按如下规则把每一列投影到一个向量 `v` 里：

* `v[i] = 1`   如果存在 `x` 使得 `image[x][i] = 1`
* `v[i] = 0`   其他情况

也就是说

> 如果某一列有黑色像素，那么这一列的投影对应的格子是黑色的，否则是白色的。

类似的，我们对行做同样的操作，将二维的图片投影到一维的列向量里。两个投影的向量如图 1 所示。

现在我们来说明下面的引理：

*引理*
>如果只有一个黑色像素区域，那么一维投影数组里所有黑色的像素是连在一块的。

*反证法证明*
>假设结论不成立，有不连接的黑色像素块 `i` 和 `j` ，在一维数组中 `i < j` 。此时，存在一列 `k` 在 `(i, j)` 中且列 `k` 在二维数组中没有黑色像素。此时，二维数组中至少有两个黑色区域被列 `k` 分隔开，这与“只有一个黑色区域”矛盾。

因此，我们得出结论所有一维数组中的黑色像素是连在一起的。

有了这个引理，我们有如下算法：

* 将二维数组投影到一个列数组和一个行数组中
* 在行数组 `[0, y)` 中二分查找 `left`
* 在行数组 `[y + 1， n)` 中二分查找 `right`
* 在列数组 `[0, x)` 中二分查找 `top`
* 在列数组 `[x + 1, m)` 中二分查找 `bottom`
* 返回 `(right - left) * (bottom - top)`

然而，投影这一步的时间代价就需要 $O(mn)$ ，这占据了整个算法的主要时间。如果仅仅这样，我们没法比之前的方法取得更好的效果。

这里的技巧是，我们不需要把整个投影过程当做预处理过程，我们可以只在必要的时候做这个步骤。

回想一下一维数组里的二分查找，每一次我们只检查当前区间中心的元素，来决定下一次查找是在左区间还是右区间。

在二维数组中，我们可以做类似的事情。唯一的不同是这里的元素不是一个数字而是一个向量。比方说，一个 `m * n` 的矩阵可以被看成 `n` 个列向量。

在这个 `n` 个元素（向量）里，我们进行二分查找来找到 `left` 或者 `right` 。每一次我们只检查当前区间最中心的一个列向量，来决定下一次我们查找哪一边。

最后总共会查找 $O(\log n)$ 个向量，每一次检查需要 $O(m)$ 的时间（我们简单地遍历向量中所有的 `m` 个元素）

所以总共需要 $O(m \log n)$ 来找到 `left` 和 `right` 。
类似地，我们需要 $O(n \log m)$ 的时间去找到 `top` 和 `bottom` 。整个算法的时间复杂度为 $O(m \log n + n \log m)$ 。

```java []
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int m = image.length, n = image[0].length;
        int left = searchColumns(image, 0, y, 0, m, true);
        int right = searchColumns(image, y + 1, n, 0, m, false);
        int top = searchRows(image, 0, x, left, right, true);
        int bottom = searchRows(image, x + 1, m, left, right, false);
        return (right - left) * (bottom - top);
    }
    private int searchColumns(char[][] image, int i, int j, int top, int bottom, boolean whiteToBlack) {
        while (i != j) {
            int k = top, mid = (i + j) / 2;
            while (k < bottom && image[k][mid] == '0') ++k;
            if (k < bottom == whiteToBlack) // k < bottom means the column mid has black pixel
                j = mid; //search the boundary in the smaller half
            else
                i = mid + 1; //search the boundary in the greater half
        }
        return i;
    }
    private int searchRows(char[][] image, int i, int j, int left, int right, boolean whiteToBlack) {
        while (i != j) {
            int k = left, mid = (i + j) / 2;
            while (k < right && image[mid][k] == '0') ++k;
            if (k < right == whiteToBlack) // k < right means the row mid has black pixel
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(m \log n + n \log m)$ 。

这里，$m$ 和 $n$ 是图像的宽和高。我们在二分查找的过程中每次都要执行一个线性查找。前一部分介绍了这个算法是如何运作的。

* 空间复杂度： $O(1)$ 。

宽搜和线性查找都只需要线性大小的额外空间。
