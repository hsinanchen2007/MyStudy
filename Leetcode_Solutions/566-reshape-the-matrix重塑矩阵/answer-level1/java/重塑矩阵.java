#### 方法一 使用队列 [通过]

**算法**

最简单的方法是通过以行方式读取元素来提取给定矩阵的所有元素。在此实现中，我们使用队列来放置提取的元素。然后，我们可以取出以串行顺序形成的队列元素，并再次按行逐行排列所得到的所需矩阵中的元素。

如果原始矩阵中的元素数量不等于所得矩阵中的元素数量，则不可能形成所得矩阵。

```java [solution1-Java]
public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int[][] res = new int[r][c];
        if (nums.length == 0 || r * c != nums.length * nums[0].length)
            return nums;
        int count = 0;
        Queue < Integer > queue = new LinkedList < > ();
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[0].length; j++) {
                queue.add(nums[i][j]);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = queue.remove();
            }
        }
        return res;
    }
}
```
**复杂度分析**

* 时间复杂度：$O(m*n)$。我们遍历 $m * n$ 元素两次。这里，$m$ 和 $n$ 分别表示给定矩阵的行数和列数。

* 空间复杂度：$O(m*n)$。形成的队列大小为 $m*n$ 。

---
#### 方法二 不用额外空间 [通过]

**算法**

我们不必像在暴力方法中那样不必要地使用队列，而是可以在逐行顺序迭代给定矩阵的同时，直接将数字放在结果矩阵中。在将数字放入结果数组时，我们固定一个特定的行，并继续增加列数，直到我们到达$c$指示的所需列的末尾。此时，我们通过递增来更新行索引，并将列索引重置为从0开始。因此，我们可以节省队列消耗的空间，以便存储只需要复制到新数组中的数据。

```java [solution2-Java]
public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int[][] res = new int[r][c];
        if (nums.length == 0 || r * c != nums.length * nums[0].length)
            return nums;
        int rows = 0, cols = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[0].length; j++) {
                res[rows][cols] = nums[i][j];
                cols++;
                if (cols == c) {
                    rows++;
                    cols = 0;
                }
            }
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(m*n)$。我们只遍历整个矩阵 $m*n$。这里，$m$ 和 $n$ 指的是给定矩阵中的行数和列数。


* 空间复杂度：$O(m*n)$。使用大小为 $m*n$ 的结果矩阵。

---

#### 方法三  除法和取模 [通过]

**算法**

在上一种方法中，我们需要跟踪我们何时到达结果矩阵的列的末尾，并且需要通过每次检查当前索引来更新当前行和列号以放置提取的元素。我们可以利用数学来帮助解决，而不是在每一步都进行限制性检查。

这种方法背后的想法如下。你知道二维数组是如何存储在主存中的（本质上是一维）吗？它仅在内部表示为一维阵列。元素$nums [i] [j]$ $nums$ 数组通过使用以下形式的索引以一维数组的形式表示：$ nums [n * i + j] $，其中$ m $是给定矩阵中的列数。以相反的顺序查看相同的内容，同时将元素放在结果矩阵中的元素中，我们可以使用$ count $变量，该变量对于遍历的每个元素都会递增，就像我们将元素放在一维中一样结果数组。但是，要将$ count $转换回列数为$ c $的二维矩阵索引，我们可以获得$ res [count / c] [count \％c] $的索引，其中$ count / c $是行号和$ count \％c $是列数字。因此，我们可以节省每一步所需的额外检查。

```java [solution3-Java]
public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int[][] res = new int[r][c];
        if (nums.length == 0 || r * c != nums.length * nums[0].length)
            return nums;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[0].length; j++) {
                res[count / c][count % c] = nums[i][j];
                count++;
            }
        }
        return res;
    }
}
```
**复杂度分析**

* 时间复杂度：$O(m*n)$。我们只遍历整个矩阵 $m*n$ 。这里，$m$ 和 $n$ 指的是给定矩阵中的行数和列数。

* 空间复杂度：$O(m*n)$。使用大小为 $m*n$ 的矩阵存储结果。

---