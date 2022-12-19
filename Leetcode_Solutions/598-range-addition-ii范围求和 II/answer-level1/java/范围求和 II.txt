#### 方法 1：暴力 [Time Limit Exceeded]

最简单的方法是创建一个 $m * n$ 的二维数组 $arr$，对所有操作都逐一将范围内的元素加一，最后数一遍最大元素的数目。由于我们知道所有操作总是会影响到 $(0,0)$，所以元素 $arr[0][0]$ 总是最大的。在所有操作执行完之后，我们数有多少个跟 $arr[0][0]$ 一样大的元素就是答案。

```Java []
public class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int[][] arr = new int[m][n];
        for (int[] op: ops) {
            for (int i = 0; i < op[0]; i++) {
                for (int j = 0; j < op[1]; j++) {
                    arr[i][j] += 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == arr[0][0])
                    count++;
            }
        }
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(x \times m \times n)$。数组被更新 $x$ 次，$x$ 是操作的次数，也就是 $ops.lenth$。

* 空间复杂度：$O(m \times n)$。使用了大小为 $m \times n$ 的数组。

#### 方法 2：一遍遍历 [Accepted]

**算法**

正如题目描述，所有操作都是在一个初始元素全为 0 的子矩阵上进行。每个矩形的左上角坐标都是 $(0,0)$ 而右下角坐标是 每个操作给出的坐标 $(i,j)$。

最大元素是所有操作都会影响到的一个元素，下图是在初始 $M$ 矩阵上执行了 2 次操作的一个示例图。

![image.png](https://pic.leetcode-cn.com/26e0a0c8beab6fcc0edfc099a9188179210b6b627f5a77970b672338a99f864a-image.png){:width=600}
{:align=center}

从这张图中，我们可以观察到最大元素会是两个操作对应矩阵的交集区域。我们还可以发现要求这块区域，我们不需要将操作区域一个一个加一，我们只需要记录交集区域的右下角即可。这个角的计算方法为 $\big(x, y\big) = \big(\text{min}(op[0]), \text{min}(op[1])\big)$， 其中 $\text{min}(op[i])$ 表示所有操作的 $op[i]$ 中的最小值。

这样，最大元素的数目就是 $x \times y$。

```Java []
public class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op: ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(x)$。只需要遍历所有操作一次，$x$ 是操作的数目。

* 空间复杂度：$O(1)$。不需要额外的数组空间。
