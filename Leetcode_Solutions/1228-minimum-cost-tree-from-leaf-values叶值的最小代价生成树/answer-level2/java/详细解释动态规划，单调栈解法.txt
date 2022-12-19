## 分析：
- 这道题有两种解法，一种是动态规划，另一种是使用单调栈。
- 感谢刘岳大佬的题解。

## 代码：
### 动态规划：
- 我们发现数组中的数可以划分为两部分，一半是左子树，一半是右子树，根节点就是左边最大和右边最大的乘积。
- 而左右子树里面的值就是当数组中的数为左子树的叶子节点时的情况，右边一样。
- 直到数组中的数只有2个时，答案就是左边右边相乘。
- 因此我们可以这么看，如果2个数后面又加了一个数，那么我们可以以`01`为一个节点再和`2`划分,也可以`0`一个节点和`12`划分。
- 树的左右两边至少有1个叶子结点。
- 如果有四个数，有`0` `123`, `01` `23`, `012` `3`,同时3个数又有之前的情况。
- 因此我可以这样找状态，i代表起始点,j代表结束位置。如果我想知道4个数的答案，我就把上面划分的情况算出来，每一个情况还要加上左边和右边的最大值的乘积，作为根节点。
- 于是乎我就是要穷举所有状态。
```java
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int len = arr.length;
        int[][] dp = new int[len][len];
        int[][] maxVal = new int[len][len];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int max = 0;
                for (int k = i; k <= j; k++) if (max < arr[k]) max = arr[k];
                maxVal[i][j] = max;
            }
        }
        for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) dp[i][j] = Integer.MAX_VALUE;
        for (int i = 0; i < len; i++) dp[i][i] = 0;
        for (int i = 1; i < len; i++) { // 长度
            for (int j = 0; j < len - i; j++) { // 起始点
                for (int k = j; k < j + i; k++) { // 中间点
                    dp[j][j+i] = Math.min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + maxVal[j][k] * maxVal[k+1][j+i]);
                }
            }
        }
        return dp[0][len-1];
    }
}
```

### 单调栈：
- 单调栈的方法有点讨巧。
- 以上是我的个人理解
- 我们维护一个单调递减栈，单调递减栈有一个特性。
- 如果我们遇到一个比栈顶元素大元素，于是乎就有了两种情况。
- 我们就看前面3个。
- 第一种情况：大 小 中，这样只会将小出栈。
- 我们来算一下：
    - 大小放一块：`大 * 小 + 大 * 中`
    - 小中放一块：`小 * 中 + 大 * 中`
    - 所以把小和中放在一起得到的值更小。
- 第二种情况： 中 小 大， 小 中 都会出栈
    - 中小放在一块：`中 * 小 + 中 * 大`
    - 小大放在一块：`小 * 大 + 中 * 大`
    - 因此把中小放在一起得到的值更小。
- 由此得出结论如果遇到出栈情况，我们将小的那个(也就是栈顶元素)和它左边或右边较小的那个放在一起得到的答案是最优。
- 同时，小的那个元素就不再需要了，我们只看大的那个元素可能还会和别的值相乘。
- 最后将值放入栈后，栈内元素单调递减，于是就有了`大 中 小`,这个可以自己去证。会发现还是把`中小`放在一起最优。
```java
class Solution {
    public int mctFromLeafValues(int[] arr) {
        Stack<Integer> stack = new Stack();
        stack.push(Integer.MAX_VALUE);
        int ans = 0;
        for (int n : arr) {
            while (stack.peek() < n) ans += stack.pop() * Math.min(stack.peek(), n);
            stack.push(n);
        }
        while (stack.size() > 2) ans += stack.pop() * stack.peek();
        return ans;
    }
}
```