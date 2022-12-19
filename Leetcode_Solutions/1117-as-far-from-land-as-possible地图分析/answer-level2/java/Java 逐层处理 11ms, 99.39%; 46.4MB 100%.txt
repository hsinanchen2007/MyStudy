### 解题思路
挑了几个答案，没看到我这种解法所以写一下，具体我这个叫啥我也不知道。。空间复杂度O(M*N), 时间复杂度粗略想了一下是O(M*N)。

我的思路是这样的，如果是人去解这个题，最简单的想法就是逐行遍历, 单独开辟一个空间，记录下每个点的距离信息，最后遍历一遍求最大值。

#### 1.地图只有一行时
此时我们显然会想到从左到右逐个节点观察，假如遇到海洋节点，此时比较简单，我可以忽略右侧的节点，只取左侧的节点距离+1，至于右侧怎么处理后面再说。
假如遇到陆地节点，那么陆地本身肯定是0，此时我就需要更新左侧的节点了，因为之前处理左侧节点时，我们并没有考虑右侧情况，所以需要一直往左更新距离，
直到待更新的节点距离足够小。

假设地图大小为1*N，我们需要理解的是，当我们发现第n(1<=n<=N)个节点为陆地，进而更新其左侧节点时，假如判断到第n1(n1<n)节点无需更新，此时意味着
1,2,3...n1都无需更新。

#### 2.地图有多行时
当我们处理第m行时，对第m行本身来说，我们仍然可以复用对一行的处理逻辑，区别在于当节点(m,n)为海洋节点时，左侧(m,n-1)和上侧(m-1,n)的节点都需要考虑。
当遇到陆地节点时，不仅需要递归更新左侧节点(m,n-1)，还需要递归更新上侧的节点(m-1,n)。并且，让我们想象一个只在右下角为陆地的地图，当我们更新(m-1,n)后，
我们仍然需要递归处理(m-1,n)的左侧节点(m-1,n-1)和上侧节点(m-2,n)。所以更新操作本身必须包含一个递归的更新操作。

#### 正确性分析
让我们想象一个只在中央有陆地的地图，那么显然陆地的左上区域是更新陆地节点时递归更新的，因此没有问题。而更新陆地的右侧海洋节点时，会触发海洋上侧的
节点更新，因此也没有问题。陆地下侧的海洋更新时会用到陆地的距离，并更新左侧，而右侧更新时又会用到陆地下侧的节点，依次类推，这个算法是正确的。

#### 性能分析
遍历本身需要M*N，而最后算结果需要额外一次遍历，因此需要2*M*N。
我不太会分析，但是粗略想一下每个海洋节点的更新次数是一个有限的值，一次遍历时更新，一次被动更新。当(m,n)为陆地时，(m+1,n)或者(m,n+1)的陆地更新不会触发(m,n)
左上区域的更新。

隐含的一个问题是递归会不会导致栈溢出，由于题目的地图大小有限，因此无需考虑。实际上更新左侧节点时似乎可以用迭代替换。

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        if (grid.length == 0) {
            return -1;
        }

        Integer[][] distances = new Integer[grid.length][grid[0].length];
        boolean hasLand = false;
        boolean hasOcean = false;
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == 0) {
                    hasOcean = true;
                    updateDistance(distances, row, col, getCurMinDistance(distances, row, col));
                } else {
                    hasLand = true;
                    updateDistance(distances, row, col, 0);
                }
            }
        }

        if (!hasLand || !hasOcean) {
            return -1;
        }

        int maxDis = -1;
        for (int row = 0; row < distances.length; row++) {
            for (int col = 0; col < distances[0].length; col++) {
                if (maxDis < distances[row][col]) {
                    maxDis = distances[row][col];
                }
            }
        }

        return maxDis;
    }

    // 获取当前海洋节点的最小距离，取左侧和上侧节点距离较小者+1
    private int getCurMinDistance(Integer[][] distances, int row, int col) {
        int leftDis = Integer.MAX_VALUE; // 使用MAX_VALUE表示尚未处理
        int topDis = Integer.MAX_VALUE;

        // 获取左侧节点
        if (col > 0) {
            leftDis = distances[row][col - 1];
        }

        // 获取上侧节点
        if (row > 0) {
            topDis = distances[row - 1][col];
        }

        // 默认值处理，防止溢出导致值倒转
        if (Math.min(leftDis, topDis) == Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }

        return Math.min(leftDis, topDis) + 1;
    }

    // 更新当前节点，并递归更新上侧和左侧的节点
    private void updateDistance(Integer[][] distances, int row, int col, int distance) {
        // 边界判断
        if (row < 0 || col < 0) {
            return;
        }

        // 终止条件，当前值已经很小了，无需更新
        if (distances[row][col] != null && distances[row][col] <= distance) {
            return;
        }

        distances[row][col] = distance;
        if (distance == Integer.MAX_VALUE) {// 默认值处理，无需继续更新
            return;
        }

        updateDistance(distances, row - 1, col, distance + 1);//更新上侧节点
        updateDistance(distances, row, col - 1, distance + 1);//更新左侧节点，这一步操作似乎可以用迭代替换掉
    }
}
```