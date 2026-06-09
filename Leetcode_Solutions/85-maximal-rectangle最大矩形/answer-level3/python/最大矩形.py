#### 方法一: 暴力算法

**算法**

最原始地，我们可以列举每个可能的矩形。这可以通过遍历所有的`(x1, y1)`  `(x2, y2)` 坐标，并以它们为对角顶点来完成。该方法过慢，不足以通过所有测试用例。


**复杂度分析**

* 时间复杂度 : $O(N^3M^3)$，其中 `N`为行数，  `M` 为列数。

    遍历全部坐标的复杂度是$O(N^2M^2)$，遍历以该两点为对角顶点的矩形又会耗费 $O(NM)$。故总体复杂度为$O(NM) * O(N^2M^2) = O(N^3M^3)$。

* 空间复杂度 : $O(1)$.


---

#### 方法二: 动态规划 - 使用柱状图的优化暴力方法

**算法**

我们可以以常数时间计算出在给定的坐标结束的矩形的最大宽度。我们可以通过记录每一行中每一个方块连续的“1”的数量来实现这一点。每遍历完一行，就更新该点的最大可能宽度。通过以下代码即可实现。 `row[i] = row[i - 1] + 1 if row[i] == '1'`.


<![image.png](https://pic.leetcode-cn.com/b1aae9ca33baaad3ee88e650dc13730689c6c57a3603996c1eae23902a13ef42-image.png),![image.png](https://pic.leetcode-cn.com/6f6bc9292915b697eba1f571ed38b63891b98a67f29a25e3c0b2f61f194c1617-image.png),![image.png](https://pic.leetcode-cn.com/c7b14e9ec2ef9064bdd222d343877c0e49afa72d9b1a79051214554e457bfd3d-image.png),![image.png](https://pic.leetcode-cn.com/950f47d81259d0a32cae15c93b3b1f5ea323f93fc143b76e67bffbd1709f6c47-image.png),![image.png](https://pic.leetcode-cn.com/86f5f7506859bf34f8e4ef2b5529c3a3f5efad4ad2c29262103166ede10f4545-image.png),![image.png](https://pic.leetcode-cn.com/0152b496312caf43bda2f4e03377c74c45b91deb7664454e5ed6808c4c3ed648-image.png),![image.png](https://pic.leetcode-cn.com/ab17561e25fee6e943ebe1a0678480f7fc75cef29008a4ed470067c51bd0831b-image.png),![image.png](https://pic.leetcode-cn.com/7fbe6b279af83989371f029c6df3bb19e7b78d0e53887e5e7e61ba264445bb14-image.png),![image.png](https://pic.leetcode-cn.com/4b27035046be4db27298c69bcdd6f2b4b3122401b62f87feca52c41f974a966e-image.png),![image.png](https://pic.leetcode-cn.com/9c2cbf02a9a8495cbc0179c6faed52db37ca20ba616fa33801a27d37ef0fa5c3-image.png)>

一旦我们知道了每个点对应的最大宽度，我们就可以在线性时间内计算出以该点为右下角的最大矩形。当我们遍历列时，可知从初始点到当前点矩形的最大宽度，就是我们遇到的每个最大宽度的最小值。
我们定义：

$$maxWidth = min(maxWidth, widthHere)$$

$$curArea = maxWidth * (curre***ow - originalRow + 1)$$

$$maxArea = max(maxArea, curArea)$$

下面的动画有助于理解。给定每个点的最大宽度，可计算出底端黄色方块的最大矩形面积。


<![image.png](https://pic.leetcode-cn.com/bb40b26be66a20c49bf797b908fd00589c1df90c27c1e4789323e1d0a983b8e6-image.png),![image.png](https://pic.leetcode-cn.com/14a6767d8e49b00e351b6e052143dfa826148c22a7e13c3a05c55ea401d05f18-image.png),![image.png](https://pic.leetcode-cn.com/d553e8ea8ba5f36a01dadd3530a31cadc2a98aa5b7d8f591fcb36b6c2604784a-image.png),![image.png](https://pic.leetcode-cn.com/31d96446efe7b2f759b5caefb262310b6807219b7f9974ebfb00b6b905a84adb-image.png),![image.png](https://pic.leetcode-cn.com/7f6ed0d6f2e41a397cb3256cfb01731e4aba8923605cabb5710b544a5822431c-image.png),![image.png](https://pic.leetcode-cn.com/27ee13f89d42a54d0e31cffd877eefa91b6abff06939c8a13fbb997e654a2eec-image.png),![image.png](https://pic.leetcode-cn.com/c63ef207b988b004efc6fc7c2755a1653f62f9a09ccb4210169f692fc1c7cebf-image.png)>

对每个点重复这一过程，就可以得到全局最大。

注意，我们预计算最大宽度的方法事实上将输入转化成了一系列的柱状图，每一栏是一个新的柱状图。我们在针对每个柱状图计算最大面积。

![image.png](https://pic.leetcode-cn.com/ffba9c5b4b0799150e5b798a73d96c8313522362e9b5290dcff7d9a43f46ba14-image.png){:width="300px"}
{:align="center"}

于是，上述方法本质上是 [84 - 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/) 题中优化暴力算法的复用。


```Python [solution 2]
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        maxarea = 0

        dp = [[0] * len(matrix[0]) for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '0': continue

                # compute the maximum width and update dp with it
                width = dp[i][j] = dp[i][j-1] + 1 if j else 1

                # compute the maximum area rectangle with a lower right corner at [i, j]
                for k in range(i, -1, -1):
                    width = min(width, dp[k][j])
                    maxarea = max(maxarea, width * (i-k+1))
        return maxarea

```

```Java [solution 2]
class Solution {
    public int maximalRectangle(char[][] matrix) {

        if (matrix.length == 0) return 0;
        int maxarea = 0;
        int[][] dp = new int[matrix.length][matrix[0].length];

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if (matrix[i][j] == '1'){

                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0? 1 : dp[i][j-1] + 1;

                    int width = dp[i][j];

                    // compute the maximum area rectangle with a lower right corner at [i, j]
                    for(int k = i; k >= 0; k--){
                        width = Math.min(width, dp[k][j]);
                        maxarea = Math.max(maxarea, width * (i - k + 1));
                    }
                }
            }
        } return maxarea;
    }
}
```



**复杂度分析**

* 时间复杂度 : $O(N^2M)$。由于需要遍历同一列中的值，计算每个点对应最大面积需要$O(N)$。对全部$N * M$个点都要计算，因此总共$O(N) * O(NM) = O(N^2M)$。

* 空间复杂度 : $O(NM)$。我们分配了一个等大的数组，用于存储每个点的最大宽度。
<br />
<br />

---

#### 方法三：使用柱状图 - 栈 

**算法**

在上一方法中我们讨论了将输入拆分成一系列的柱状图，每个柱状图代表一列的子结构。为了计算长方形的最大面积，我们仅仅需要计算每个柱状图中的最大面积并找到全局最大值（注意后面的解法对每一行而非列建立了柱状图，两者思想一致）。

既然我们已经有了 [84 - 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)，可以直接使用该题题解中最快的基于栈的解法 [点击这里](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/) ，并将其应用在我们生成的柱状图中。想详细了解该算法的原理，请点击上面的链接。 


```Python [solution 3]
class Solution:

    # Get the maximum area in a histogram given its heights
    def leetcode84(self, heights):
        stack = [-1]

        maxarea = 0
        for i in range(len(heights)):

            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                maxarea = max(maxarea, heights[stack.pop()] * (i - stack[-1] - 1))
            stack.append(i)

        while stack[-1] != -1:
            maxarea = max(maxarea, heights[stack.pop()] * (len(heights) - stack[-1] - 1))
        return maxarea


    def maximalRectangle(self, matrix: List[List[str]]) -> int:

        if not matrix: return 0

        maxarea = 0
        dp = [0] * len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):

                # update the state of this row's histogram using the last row's histogram
                # by keeping track of the number of consecutive ones

                dp[j] = dp[j] + 1 if matrix[i][j] == '1' else 0

            # update maxarea with the maximum area from this row's histogram
            maxarea = max(maxarea, self.leetcode84(dp))
        return maxarea
```

```Java [solution 3]
class Solution {

    // Get the maximum area in a histogram given its heights
    public int leetcode84(int[] heights) {
        Stack < Integer > stack = new Stack < > ();
        stack.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.length; ++i) {
            while (stack.peek() != -1 && heights[stack.peek()] >= heights[i])
                maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack.peek() - 1));
            stack.push(i);
        }
        while (stack.peek() != -1)
            maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack.peek() -1));
        return maxarea;
    }

    public int maximalRectangle(char[][] matrix) {

        if (matrix.length == 0) return 0;
        int maxarea = 0;
        int[] dp = new int[matrix[0].length];

        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[0].length; j++) {

                // update the state of this row's histogram using the last row's histogram
                // by keeping track of the number of consecutive ones

                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update maxarea with the maximum area from this row's histogram
            maxarea = Math.max(maxarea, leetcode84(dp));
        } return maxarea;
    }
}
```


其中 `力扣 84` 下的代码是从 [84 - 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)的题解中复制来的。

**复杂度分析**

* 时间复杂度 : $O(NM)$。对每一行运行 `力扣 84` 需要 `M` (每行长度) 时间，运行了 `N` 次，共计 $O(NM)$。

* 空间复杂度 : $O(M)$。我们声明了长度等于列数的数组，用于存储每一行的宽度。
<br />
<br />

---

#### 方法四：动态规划 - 每个点的最大高度

**直觉**

想象一个算法，对于每个点我们会通过以下步骤计算一个矩形：

 * 不断向上方遍历，直到遇到“0”，以此找到矩形的最大高度。

 * 向左右两边扩展，直到无法容纳矩形最大高度。

例如，找到黄色点对应的矩形：

<![image.png](https://pic.leetcode-cn.com/7afdf3b28c24af7ac7a9d97463823ebfe1e43580c443cfb8482ad9b02723f70f-image.png),![image.png](https://pic.leetcode-cn.com/e41e88f92dcb5597a1dd336e0ab713b4c2e3281e99d144e58bbffc7c89836716-image.png),![image.png](https://pic.leetcode-cn.com/587924f9696b0ea30e056daa03520fc400c7688ba26be2acab4cd9775d76e385-image.png),![image.png](https://pic.leetcode-cn.com/ef911caf1a48bdeaf7396acdbca997e4eb65bce3cadb7ea529027c71754ef815-image.png),![image.png](https://pic.leetcode-cn.com/1c943eb17b6dad2022e4417a85098488405adaefd492fa8a27d5b7c025b80f25-image.png),![image.png](https://pic.leetcode-cn.com/492476afc9693ce2cb7352c9c29094508573b4635b121633eafb07c382115141-image.png)>

我们知道，最大矩形必为用这种方式构建的矩形之一。 

给定一个最大矩形，其高为 `h`， 左边界 `l`，右边界 `r`，在矩形的底边，区间 `[l, r]`内必然存在一点，其上连续1的个数（高度）`<=h`。若该点存在，则由于边界内的高度必能容纳`h`，以上述方法定义的矩形会向上延伸到高度`h`，再左右扩展到边界 `[l, r]` ，于是该矩形就是最大矩形。

若不存在这样的点，则由于`[l, r]`内所有的高度均大于`h`，可以通过延伸高度来生成更大的矩形，因此该矩形不可能最大。

综上，对于每个点，只需要计算`h`， `l`，和 `r` - 矩形的高，左边界和右边界。

使用动态规划，我们可以在线性时间内用上一行每个点的 `h`，`l`，和 `r` 计算出下一行每个点的的`h`，`l`，和`r`。


**算法**

给定一行 `matrix[i]`，我们通过定义三个数组`height`，`left`，和 `right`来记录每个点的`h`，`l`，和 `r`。`height[j]` 对应`matrix[i][j]`的高，以此类推。

问题转化为如何更新每个数组。

Height:

这个比较容易。 `h` 的定义是从该点出发连续的1的个数。我们从方法二中已经学会了在一行中计算的方法:

    row[j] = row[j - 1] + 1 if row[j] == '1'

只需要一点改动即可:

    new_height[j] = old_height[j] + 1 if row[j] == '1' else 0


Left:

考虑哪些因素会导致矩形左边界的改变。由于当前行之上的全部0已经考虑在当前版本的`left`中，唯一能影响`left`就是在当前行遇到0。

因此我们可以定义:

    new_left[j] = max(old_left[j], cur_left)

`cur_left`是我们遇到的最右边的0的序号加1。当我们将矩形向左 “扩展” ，我们知道，不能超过该点，否则会遇到0。

Right:

我们可以沿用 `left` 的思路，定义:

    new_right[j] = min(old_right[j], cur_right)

`cur_right` 是我们遇到的最左边的0的序号。简便起见，我们不把 `cur_right` 减去1 (就像我们给`cur_left`加上1那样) ，这样我们就可以用`height[j] * (right[j] - left[j])` 而非`height[j] * (right[j] + 1 - left[j])`来计算矩形面积。

这意味着， _严格地说_ ，矩形的底边由半开半闭区间`[l, r)` 决定，而非闭区间 `[l, r]`，且 `right`比右边界大1。尽管不这样做算法也可以正确运行，但这样会让计算看起来更简洁。

注意，为了正确的记录 `cur_right`，我们需要从右向左迭代。因此，更新`right`时需要从右向左。

一旦`left`，`right`，和 `height`数组能够正确更新，我们就只需要计算每个矩形的面积。

由于我们知道矩形 `j`的边界和高，可以简单地用`height[j] * (right[j] - left[j])`来计算面积，若`j`的面积 大于`max_area`，则更新之。



```Python [solution 4]

class Solution:

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0

        m = len(matrix)
        n = len(matrix[0])

        left = [0] * n # initialize left as the leftmost boundary possible
        right = [n] * n # initialize right as the rightmost boundary possible
        height = [0] * n

        maxarea = 0

        for i in range(m):

            cur_left, cur_right = 0, n
            # update height
            for j in range(n):
                if matrix[i][j] == '1': height[j] += 1
                else: height[j] = 0
            # update left
            for j in range(n):
                if matrix[i][j] == '1': left[j] = max(left[j], cur_left)
                else:
                    left[j] = 0
                    cur_left = j + 1
            # update right
            for j in range(n-1, -1, -1):
                if matrix[i][j] == '1': right[j] = min(right[j], cur_right)
                else:
                    right[j] = n
                    cur_right = j
            # update the area
            for j in range(n):
                maxarea = max(maxarea, height[j] * (right[j] - left[j]))

        return maxarea

```

```Java [solution 4]

class Solution {

    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0) return 0;
        int m = matrix.length;
        int n = matrix[0].length;

        int[] left = new int[n]; // initialize left as the leftmost boundary possible
        int[] right = new int[n];
        int[] height = new int[n];

        Arrays.fill(right, n); // initialize right as the rightmost boundary possible

        int maxarea = 0;
        for(int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            // update height
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            // update left
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='1') left[j]=Math.max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // update right
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') right[j] = Math.min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}    
            }
            // update area
            for(int j = 0; j < n; j++) {
                maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
            }
        return maxarea;
    }
}
```


*复杂度分析**

* 时间复杂度 : $O(NM)$。每次对于`N`的迭代我们会对`M`迭代常数次。

* 空间复杂度 : $O(M)$， `M` 是我们保留的额外数组的长度。