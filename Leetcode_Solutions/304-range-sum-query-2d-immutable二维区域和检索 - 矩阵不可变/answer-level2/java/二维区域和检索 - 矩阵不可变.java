####  方法一：暴力法[超出时间限制]
**算法：**
每次调用 sumregion 时，我们都使用两重循环来求和 $(row1，col1)\rightarrow(row2，col2)$ 中的所有元素。 
```Java []
private int[][] data;

public NumMatrix(int[][] matrix) {
    data = matrix;
}

public int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int r = row1; r <= row2; r++) {
        for (int c = col1; c <= col2; c++) {
            sum += data[r][c];
        }
    }
    return sum;
}
```

**复杂度分析**

* 时间复杂度：每次查询的时间 $O(mn)$。假设 $m$ 和 $n$ 分别代表行数和列数，每个 sumregion 查询最多需要访问 $m \times n$ 元素。
* 空间复杂度：$O(1)$，数据是对矩阵的引用，不是它的副本。


####  方法二：缓存 [超过内存限制]
因为 sumregion 可以多次调用，所以我们肯定需要做一些预处理。 

**算法：**
我们可以通过预先计算所有可能的矩形区域和并将其存储在哈希表中，从而在额外的空间中换取速度。每个 sumregion 查询现在只需要恒定的时间复杂度。 
**复杂度分析**

* 时间复杂度：每次查询的时间 $O(1)$。$O(m^2n^2)$ 的时间预计算。每个 sumregion 查询需要 $O(1)$ 时间，因为哈希表查找的时间复杂度是恒定的。预计算将花费 $O(m^2n^2)$ 时间，因为总共需要缓存 $M^2 \times n^2$ 的可能值。 
* 空间复杂度：$O(m^2n^2)$。由于矩形区域的左上方和右下方的可能性各不相同，因此所需的额外空间为 $O(m^2n^2)$。 


####  方法三：缓存行
还记得我们使用累积和数组的一维版本吗？我们可以直接用它来解这个二维版本吗？ 

**算法：**
尝试将二维矩阵视为一维数组的 $m$ 行。为了找到区域和，我们只需要在区域中逐行累积和。 

```Java []
private int[][] dp;

public NumMatrix(int[][] matrix) {
    if (matrix.length == 0 || matrix[0].length == 0) return;
    dp = new int[matrix.length][matrix[0].length + 1];
    for (int r = 0; r < matrix.length; r++) {
        for (int c = 0; c < matrix[0].length; c++) {
            dp[r][c + 1] = dp[r][c] + matrix[r][c];
        }
    }
}

public int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int row = row1; row <= row2; row++) {
        sum += dp[row][col2 + 1] - dp[row][col1];
    }
    return sum;
}
```

**复杂度分析**

* 时间复杂度：每次查询的时间 $O(m)$。$O(mn)$ 时间预计算。构造函数中的预计算需要 $O(mn)$ 时间。sumregion 查询需要 $O(m)$ 时间。 
* 空间复杂度：$O(mn)$。该算法使用 $O(mn)$ 空间存储所有行的累积和。


####  方法四：智能缓存 
**算法：**
我们在一维版本中使用了累积和数组。我们注意到累积和是根据索引 0 处的原点计算的。将这个类比扩展到二维情况，我们可以预先计算出一个与原点相关的累积区域和，即 $(0,0)$。 


![image.png](https://pic.leetcode-cn.com/dca167f68285ff2353eb3c186792098aaf866459958af0bf0dbe8c82602e2fa0-image.png){:width=150}

Sum(OD)是相对于原点(0,0)的累计区域和。              
如何使用预先计算的累积区域和得出 $Sum(ABCD)$ 呢？



![image.png](https://pic.leetcode-cn.com/d4ad28b52f13edcc7fa09517e2f425d9b4dfbaaad7b56a9ec0b1e7e97e8e0888-image.png){:width=150}

Sum(OB)是矩形顶部的累积区域和。


![image.png](https://pic.leetcode-cn.com/da44239ca4e857d4d1974f449a3f283a3863403d5ce677f86bd61fb63b34ac04-image.png){:width=150}

Sum(OC)是矩形左侧的累积区域和。


![image.png](https://pic.leetcode-cn.com/227db43a25fb52ddccbc07c09afdc66ea60f97f8d636bbdaf68f167005bf6f75-image.png){:width=150}


Sum(OA) 是矩形左上角的累积区域和。              
区域 $Sum(OA)$ 由 $Sum(OB)$ 和 $Sum(OC)$两次覆盖。我们可以使用包含排除原则计算 $Sum(ABCD)$ 如下：              
$$ sum(abcd)=sum(od)-sum(ob)-sum(oc)+sum(oa)$$ 


```Java []
private int[][] dp;

public NumMatrix(int[][] matrix) {
    if (matrix.length == 0 || matrix[0].length == 0) return;
    dp = new int[matrix.length + 1][matrix[0].length + 1];
    for (int r = 0; r < matrix.length; r++) {
        for (int c = 0; c < matrix[0].length; c++) {
            dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
        }
    }
}

public int sumRegion(int row1, int col1, int row2, int col2) {
    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
}
```

**复杂度分析**

* 时间复杂度：每次查询时间 $O(1)$，$O(mn)$ 的时间预计算。构造函数中的预计算需要 $O(mn)$ 时间。每个 sumregion 查询需要 $O(1)$ 时间 。
* 空间复杂度：$O(mn)$，该算法使用 $O(mn)$ 空间存储累积区域和。
