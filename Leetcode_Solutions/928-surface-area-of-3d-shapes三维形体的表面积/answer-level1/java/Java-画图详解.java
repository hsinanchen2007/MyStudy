### 解题思路
很多小伙伴在读题的时候就陷入了沉思，我在这里给出其中几个示例所对应的立体图像，便于理解。有画错或者理解不到位的地方，还请指出。

**示例 1：**

输入：[[2]]
输出：10

也就是说，在 (0, 0) 位置放置两个大小都是`1×1×1`的立方体，我们将其看做是一个物体，求此状态下该物体的表面积。如下所示：

**如何计算呢？**
对于下面的这个立方体来说，其表面积为：v × 4 + 2，也就是 2 × 4 + 2 = 10。这里的`4`表示除了上下两个面以外，其余总共还有四个面，后面的`+ 2` 表示再加上`上下两个面`的面积，一共就是 10 啦。

> 注意：图中的每个方格所表示的单位长度都是 1。

![image.png](https://pic.leetcode-cn.com/10ab28fbd057dfff0baa4ac7fe1018d2c9f06028f5ea4be81b0a8c139b0fa6d5-image.png)


**示例 2：**

输入：[[1,2],[3,4]]
输出：34

也就是说：在 (0, 0) 位置放置`一个`立方体，在 (0, 1) 位置放置`两个`立方体，在 (1, 0) 位置放置`三个`立方体，在 (1, 1) 位置放置`四个`立方体，如下所示：

我不怕麻烦，一个一个给你画清楚。首先是 (0, 0) 位置上的`一个`立方体：

![image.png](https://pic.leetcode-cn.com/240105905f44bd9e4cc7ed11b0d6f8ce0a9851e400063fb100ec830640656ab1-image.png)

其次是 (0, 1) 位置放置`两个`立方体:

![image.png](https://pic.leetcode-cn.com/16535e8e126a899a9f3c57ef95e3539f34d699a9476674ad01f14ebdaf8b2bad-image.png)

然后是在 (1, 0) 位置放置`三个`立方体：

![image.png](https://pic.leetcode-cn.com/5f71ae4583ea2efe695e9e6a1c5e3727d46917e3502bfbf4a823e6a8460d1571-image.png)

最后是在 (1, 1) 位置放置`四个`立方体：

![image.png](https://pic.leetcode-cn.com/b140e45dcd1c09ebe487ed01ce40f69f09b79930dab78144a6166f71c46507b1-image.png)

再来一个整体的`后视图`，注意 (0, 0) 位置上只有一个蓝色的立方体:

![image.png](https://pic.leetcode-cn.com/1a6194e205ccfd6a9a6e4d7a6abfbfaef9a12c9657e5a01673623580259f1a7d-image.png)

**此时，对于整个大的立方体来说，我该如何计算它的表面积呢**？

- 对于实例 1 这种上下落在一起的情况来说，其表面积就是`v × 4 + 2`，v 表示当落在一起的时候立方体的个数。
- 对于实例 2 这种除了上下落在一起的情况，还有四周相邻的情况。例如两个左右相邻的立方体`共同使用`的面积是 min(v1, v2) × 2，即小的那一部分再乘 2，最后我们需要在总面积中减去这个`共同使用`的部分即可。


### 代码
```java
// 代码来源：https://leetcode.com/problems/surface-area-of-3d-shapes/discuss/163414/C%2B%2BJava1-line-Python-Minus-Hidden-Area
class Solution {
    public int surfaceArea(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                // 如果当前的 [i][j] 位置存在立方体的话，我才收集所有立柱的表面积
                if (grid[i][j] > 0) {
                    res += grid[i][j] * 4 + 2;
                }
                // 以下两种情况就是分别减去左右相邻的那部分面积
                if (i > 0) {
                    res -= Math.min(grid[i][j], grid[i - 1][j]) * 2;
                }
                if (j > 0) {
                    res -= Math.min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        return res;
    }
}
```


### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)
