<br>
 
1. 给一个孩子的饼干应当尽量小并且又能满足该孩子，这样大饼干才能拿来给满足度比较大的孩子。
2. 因为满足度最小的孩子最容易得到满足，所以先满足满足度最小的孩子。

<br>

在以上的解法中，我们只在每次分配时饼干时选择一种看起来是当前最优的分配方法，但无法保证这种局部最优的分配方法最后能得到全局最优解。我们假设能得到全局最优解，并使用反证法进行证明，即假设存在一种比我们使用的贪心策略更优的最优策略。如果不存在这种最优策略，表示贪心策略就是最优策略，得到的解也就是全局最优解。

证明：假设在某次选择中，贪心策略选择给当前满足度最小的孩子分配第 m 个饼干，第 m 个饼干为可以满足该孩子的最小饼干。假设存在一种最优策略，可以给该孩子分配第 n 个饼干，并且 m < n。我们可以发现，经过这一轮分配，贪心策略分配后剩下的饼干一定有一个比最优策略来得大。因此在后续的分配中，贪心策略一定能满足更多的孩子。也就是说不存在比贪心策略更优的策略，即贪心策略就是最优策略。


<![00152.png](https://pic.leetcode-cn.com/c2c7d0027ad8d6b16208cc578a2be0da72b219ef54bfc0b52cd746779cb9972e-00152.png),![00153.png](https://pic.leetcode-cn.com/c69fbc2e69c5a8c12005dfae5368879c00e2fcfb40d7eaa0419e626fc62a645e-00153.png),![00154.png](https://pic.leetcode-cn.com/caff73f5bee26d83990d3a310052986f00ddbc7b1eaf8f39dad943da41a3d4c4-00154.png),![00155.png](https://pic.leetcode-cn.com/0ea9c1ddd7956f8bd546d618fdd8a599689e938ebbb338a2699aa3f432ec40d7-00155.png),![00156.png](https://pic.leetcode-cn.com/2e40a351c691d73cb51f8b8e6eae5c7d4a1ca11d6a532ed1d4171d0315936333-00156.png),![00157.png](https://pic.leetcode-cn.com/84f9d674d16f365578cb4fc8f1412147bbc2dbc2bdadd6e3c65661a670217e21-00157.png)>



```java
public int findContentChildren(int[] grid, int[] size) {
    if (grid == null || size == null) return 0;
    Arrays.sort(grid);
    Arrays.sort(size);
    int gi = 0, si = 0;
    while (gi < grid.length && si < size.length) {
        if (grid[gi] <= size[si]) {
            gi++;
        }
        si++;
    }
    return gi;
}
```