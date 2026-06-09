#### 方法 1：枚举

首先简化这个问题：找出一条通过点 `i` 的直线，使得经过最多的点。

我们会发现，其实只需要考虑当前点之后出现的点 `i + 1 .. N - 1` 即可，因为通过点 `i-2` 的直线已经在搜索点 `i-2` 的过程中考虑过了。

![149-1.png](https://pic.leetcode-cn.com/3881bd909daf9b0877c0b275700beaf8d0d3d35d6f75d3d3d96bc802b12ac06b-149-1.png){:width=450}
{:align=center}

思路非常简单：画一条通过点 `i` 和之后出现的点的直线，在哈希表中存储这条边并计数为 `2` = 当前这条直线上有两个点。

假设现在 `i < i + k < i + l` 这三个点在同一条直线上，当画出一条通过 `i` 和 `i+l` 的直线会发现已经记录过了，因此对更新这条边对应的计数：`count++`。

> 如何存储一条边？

如果这条线是水平的，例如 `y=c`，我们可以利用常数 `c` 作为水平直线的哈希表的键。

注意到这里所有直线都是通过同一个点 `i` 的，因此并不需要记录 `c` 的值而只需要统计水平直线的个数。

剩下的直线可以被表示成 `x = slope * y + c`，同样 `c` 也是不需要的，因为所有直线都通过同一个点 `i` 所以只需要用 `slope` 作为直线的键。

通过两个点 `1` 和 `2` 的直线方程可以 [用坐标表示](https://baike.baidu.com/item/%E7%9B%B4%E7%BA%BF/4876?fr=aladdin)为：

$$
\frac{x - x_1}{x_1 - x_2} = \frac{y - y_1}{y_1 - y_2}
$$

转换成 $x = slope \times y + c$ 表示为：

$$
slope = \frac{x_1 - x_2}{y_1 - y_2}
$$

所以，最终的算法如下：

* 初始化最大点数 `max_count = 1` 。

* 迭代所有的点 `i` 从 `0` 到 `N - 2`。
  * 对于每个点 `i` 找出通过该点直线的最大点数 `max_count_i`：
    * 初始化通过点 `i` 直线的最大点数：`count = 1`。
    * 迭代下一个顶点 `j` 从 `i+1` 到 `N-1`。
      * 如果 `j` 和 `i` 重合，更新点 `i` 相同点的个数。
      * 否则：
        * 保存通过 `i` 和 `j` 的直线。
        * 每步更新 `count`。
    * 返回结果 `max_count_i = count + duplicates`。
  * 更新结果 `max_count = max(max_count, max_count_i)`。

<![image.png](https://pic.leetcode-cn.com/7b84929d3b6f94d59a9e71115b7c4c703c7aa1c6c2438f0b6bd8038d9af4dcbc-image.png),![image.png](https://pic.leetcode-cn.com/c1170a2c694af88933dbaa8ed4373440442ab0c72f0ceb81991fd1b32f1e40ec-image.png),![image.png](https://pic.leetcode-cn.com/94d391a9987a86e4ed84a1a5312282faa00decef47b51049d3717c58a374d069-image.png),![image.png](https://pic.leetcode-cn.com/2fd323d28ea1622f22e597290bd730936568de18da3673624c79e4955b75aaac-image.png),![image.png](https://pic.leetcode-cn.com/8642c7648249b4ecb00ad6c3bcca35665287d69c376648db783c6f7681dbe5d2-image.png)>


```java [solution-Java]
import javafx.util.Pair;
class Solution {
  Point [] points;
  int n;
  HashMap<Double, Integer> lines = new HashMap<Double, Integer>();
  int horisontal_lines;

  public Pair<Integer, Integer> add_line(int i, int j, int count, int duplicates) {
    /*
    Add a line passing through i and j points.
    Update max number of points on a line containing point i.
    Update a number of duplicates of i point.
    */
    // rewrite points as coordinates
    int x1 = points[i].x;
    int y1 = points[i].y;
    int x2 = points[j].x;
    int y2 = points[j].y;
    // add a duplicate point
    if ((x1 == x2) && (y1 == y2))
      duplicates++;
    // add a horisontal line : y = const
    else if (y1 == y2) {
      horisontal_lines += 1;
      count = Math.max(horisontal_lines, count);
    }
    // add a line : x = slope * y + c
    // only slope is needed for a hash-map
    // since we always start from the same point
    else {
      double slope = 1.0 * (x1 - x2) / (y1 - y2) + 0.0;
      lines.put(slope, lines.getOrDefault(slope, 1) + 1);
      count = Math.max(lines.get(slope), count);
    }
    return new Pair(count, duplicates);
  }

  public int max_points_on_a_line_containing_point_i(int i) {
    /*
    Compute the max number of points
    for a line containing point i.
    */
    // init lines passing through point i
    lines.clear();
    horisontal_lines = 1;
    // One starts with just one point on a line : point i.
    int count = 1;
    // There is no duplicates of a point i so far.
    int duplicates = 0;

    // Compute lines passing through point i (fixed)
    // and point j (interation).
    // Update in a loop the number of points on a line
    // and the number of duplicates of point i.
    for (int j = i + 1; j < n; j++) {
      Pair<Integer, Integer> p = add_line(i, j, count, duplicates);
      count = p.getKey();
      duplicates = p.getValue();
    }
    return count + duplicates;
  }

  public int maxPoints(Point[] points) {
    this.points = points;
    // If the number of points is less than 3
    // they are all on the same line.
    n = points.length;
    if (n < 3)
      return n;

    int max_count = 1;
    // Compute in a loop a max number of points 
    // on a line containing point i.
    for (int i = 0; i < n - 1; i++)
      max_count = Math.max(max_points_on_a_line_containing_point_i(i), max_count);
    return max_count;
  }
}
```

```python [solution-Python]
class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """      
        def max_points_on_a_line_containing_point_i(i):
            """
            Compute the max number of points
            for a line containing point i.
            """
            def add_line(i, j, count, duplicates):
                """
                Add a line passing through i and j points.
                Update max number of points on a line containing point i.
                Update a number of duplicates of i point.
                """
                # rewrite points as coordinates
                x1 = points[i].x
                y1 = points[i].y
                x2 = points[j].x
                y2 = points[j].y
                # add a duplicate point
                if x1 == x2 and y1 == y2:  
                    duplicates += 1
                # add a horisontal line : y = const
                elif y1 == y2:
                    nonlocal horisontal_lines
                    horisontal_lines += 1
                    count = max(horisontal_lines, count)
                # add a line : x = slope * y + c
                # only slope is needed for a hash-map
                # since we always start from the same point
                else:
                    slope = (x1 - x2) / (y1 - y2)
                    lines[slope] = lines.get(slope, 1) + 1
                    count = max(lines[slope], count)
                return count, duplicates
            
            # init lines passing through point i
            lines, horisontal_lines = {}, 1
            # One starts with just one point on a line : point i.
            count = 1
            # There is no duplicates of a point i so far.
            duplicates = 0
            # Compute lines passing through point i (fixed)
            # and point j (interation).
            # Update in a loop the number of points on a line
            # and the number of duplicates of point i.
            for j in range(i + 1, n):
                count, duplicates = add_line(i, j, count, duplicates)
            return count + duplicates
            
        # If the number of points is less than 3
        # they are all on the same line.
        n = len(points)
        if n < 3:
            return n
        
        max_count = 1
        # Compute in a loop a max number of points 
        # on a line containing point i.
        for i in range(n - 1):
            max_count = max(max_points_on_a_line_containing_point_i(i), max_count)
        return max_count
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，因为通过点 `0` 最多有 `N-1` 条直线，通过点 `1` 最多有 `N-2` 条直线，通过点 `N-2` 只有 `1` 条直线，所以结果共有 `(N - 1) + (N - 2) + .. + 1 = N(N - 1)/2` 次操作，因此时间复杂度为 $O(N^2)$。
* 空间复杂度： $O(N)$，用来记录最多不超过 `N-1` 条直线。

