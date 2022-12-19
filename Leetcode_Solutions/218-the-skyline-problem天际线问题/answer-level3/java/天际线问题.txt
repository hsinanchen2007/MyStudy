#### 方法：分治

**想法**

这个题是一道经典的分治算法题，通常如同归并排序一样。

我们依据下面的算法流程来求解分治问题：

- 定义基本问题。

- 将问题分解为子问题，并递归地分别求解。

- 将子问题合并成原问题的解。

**算法**

求解 `n` 栋楼的天际线：

- 如果 `n == 0`：返回一个空列表

- 如果 `n == 1`：返回一栋楼的天际线

- `leftSkyline` = 求解前 n/2 栋楼的天际线。

- `rightSkyline` = 求解后 n/2 栋楼的天际线。

- 合并 `leftSkyline` 和 `rightSkyline`.

现在，让我们进一步讨论每一个步骤的细节：

**基本问题**

最基本的情况就是建筑物列表为空，此时天际线也是一个空列表。

第二种基本情况就是列表中只有一栋楼，天际线是很显然的。

![image.png](https://pic.leetcode-cn.com/db79319680dbdba42c1aff85bc01fdb1f828a6b33047d09721194b2a35df7602-image.png)

**如何拆分问题**

与归并排序的想法类似：在每一步将列表恰好拆分成两个部分：从 `0` 到 `n/2` 和 `n/2` 到 `n` ，对每一部分分别求解天际线。

![image.png](https://pic.leetcode-cn.com/d37385da0fb5f4f35a7958eb00b1f246d68487c8899b4d13b81d858548922100-image.png)

**如何合并两部分的天际线**

合并的过程十分直接明了，基于相同的归并排序的逻辑：结果天际线的高度永远是左天际线和右天际线的较大值。

![image.png](https://pic.leetcode-cn.com/80fd220374897c816ca4ea21e380e2a1f3275467902e9a9f729e19a5b6a9326c-image.png)

我们这里用两个指针 `pR` 和 `pL` 分别记录两个天际线的当前元素，再用三个整数变量 `leftY`，`rightY` 和 `currY` 分别记录 `左` 天际线、 `右` 天际线和 `合并` 天际线的当前高度。

mergeSkylines (left, right) :

- currY = leftY = rightY = 0

- 当我们在一段两个天际线都可以见到的区域时（`pR < nR` 且 `pL < nL`）：
    
    - 选择 `x` 坐标较小的一个元素，如果它是左天际线的元素，就移动 `pL` 同时更新 `leftY` 。如果是右天际线，则移动 `pR` 且更新 `rightY` 。

    - 计算较高的高度作为当前点的高度：`maxY = max(leftY, rightY)` 。
    
    - 更新结果天际线： `(x, maxY)`，前提是 `maxY` 不等于 `currY`.
    
- 如果左天际线还有元素没有被处理，也就是（`pL < nL`），则按照上述步骤处理这些元素。

- 如果右天际线还有元素没有被处理，也就是（`pR < nR`），则按照上述步骤处理这些元素。

- 返回结果天际线。

> 这里有 3 个样例来说明合并算法的过程。

![image.png](https://pic.leetcode-cn.com/5e0dfac6c937d4a03fec3955cbc3592456ae752ed281bc1761a33ae73b2f86ed-image.png)

![image.png](https://pic.leetcode-cn.com/707d3e7617b5ebe4394a4d3c4db19a0c7d13c760efcc275da15ab051a66fc820-image.png)

![image.png](https://pic.leetcode-cn.com/ad238838091649b65b9702108ce43a74a8f44176eeee8a51fdcdde594bcdedb3-image.png)

**实现**
                
```Python []
class Solution:
    def getSkyline(self, buildings: 'List[List[int]]') -> 'List[List[int]]':
        """
        Divide-and-conquer algorithm to solve skyline problem,
        which is similar with the merge sort algorithm.
        """
        n = len(buildings)
        # The base cases
        if n == 0:
            return []
        if n == 1:
            x_start, x_end, y = buildings[0]
            return [[x_start, y], [x_end, 0]] 
         
        # If there is more than one building, 
        # recursively divide the input into two subproblems.
        left_skyline = self.getSkyline(buildings[: n // 2])
        right_skyline = self.getSkyline(buildings[n // 2 :])
        
        # Merge the results of subproblem together.
        return self.merge_skylines(left_skyline, right_skyline)
    
    def merge_skylines(self, left, right):
        """
        Merge two skylines together.
        """
        def update_output(x, y):
            """
            Update the final output with the new element.
            """
            # if skyline change is not vertical - 
            # add the new point
            if not output or output[-1][0] != x:
                output.append([x, y])
            # if skyline change is vertical - 
            # update the last point
            else:
                output[-1][1] = y
        
        def append_skyline(p, lst, n, y, curr_y):
            """
            Append the rest of the skyline elements with indice (p, n)
            to the final output.
            """
            while p < n: 
                x, y = lst[p]
                p += 1
                if curr_y != y:
                    update_output(x, y)
                    curr_y = y
                
        n_l, n_r = len(left), len(right)
        p_l = p_r = 0
        curr_y  = left_y = right_y = 0
        output = []
            
        # while we're in the region where both skylines are present
        while p_l < n_l and p_r < n_r:
            point_l, point_r = left[p_l], right[p_r]
            # pick up the smallest x
            if point_l[0] < point_r[0]: 
                x, left_y = point_l
                p_l += 1
            else: 
                x, right_y = point_r 
                p_r += 1
            # max height (i.e. y) between both skylines
            max_y = max(left_y, right_y)
            # if there is a skyline change
            if curr_y != max_y:
                update_output(x, max_y)
                curr_y = max_y

        # there is only left skyline
        append_skyline(p_l, left, n_l, left_y, curr_y)

        # there is only right skyline
        append_skyline(p_r, right, n_r, right_y, curr_y)
                
        return output
```

```Java []
class Solution {
  /**
   *  Divide-and-conquer algorithm to solve skyline problem, 
   *  which is similar with the merge sort algorithm.
   */
  public List<List<Integer>> getSkyline(int[][] buildings) {
    int n = buildings.length;
    List<List<Integer>> output = new ArrayList<List<Integer>>();

    // The base cases 
    if (n == 0) return output;
    if (n == 1) {
      int xStart = buildings[0][0];
      int xEnd = buildings[0][1];
      int y = buildings[0][2];

      output.add(new ArrayList<Integer>() {{add(xStart); add(y); }});
      output.add(new ArrayList<Integer>() {{add(xEnd); add(0); }});
      // output.add(new int[]{xStart, y});
      // output.add(new int[]{xEnd, 0});
      return output;
    }

    // If there is more than one building, 
    // recursively divide the input into two subproblems.
    List<List<Integer>> leftSkyline, rightSkyline;
    leftSkyline = getSkyline(Arrays.copyOfRange(buildings, 0, n / 2));
    rightSkyline = getSkyline(Arrays.copyOfRange(buildings, n / 2, n));

    // Merge the results of subproblem together.
    return mergeSkylines(leftSkyline, rightSkyline);
  }

  /**
   *  Merge two skylines together.
   */
  public List<List<Integer>> mergeSkylines(List<List<Integer>> left, List<List<Integer>> right) {
    int nL = left.size(), nR = right.size();
    int pL = 0, pR = 0;
    int currY = 0, leftY = 0, rightY = 0;
    int x, maxY;
    List<List<Integer>> output = new ArrayList<List<Integer>>();

    // while we're in the region where both skylines are present
    while ((pL < nL) && (pR < nR)) {
      List<Integer> pointL = left.get(pL);
      List<Integer> pointR = right.get(pR);
      // pick up the smallest x
      if (pointL.get(0) < pointR.get(0)) {
        x = pointL.get(0);
        leftY = pointL.get(1);
        pL++;
      }
      else {
        x = pointR.get(0);
        rightY = pointR.get(1);
        pR++;
      }
      // max height (i.e. y) between both skylines
      maxY = Math.max(leftY, rightY);
      // update output if there is a skyline change
      if (currY != maxY) {
        updateOutput(output, x, maxY);
        currY = maxY;
      }
    }

    // there is only left skyline
    appendSkyline(output, left, pL, nL, currY);

    // there is only right skyline
    appendSkyline(output, right, pR, nR, currY);

    return output;
  }

  /**
   * Update the final output with the new element.
   */
  public void updateOutput(List<List<Integer>> output, int x, int y) {
    // if skyline change is not vertical - 
    // add the new point
    if (output.isEmpty() || output.get(output.size() - 1).get(0) != x)
      output.add(new ArrayList<Integer>() {{add(x); add(y); }});
      // if skyline change is vertical - 
      // update the last point
    else {
      output.get(output.size() - 1).set(1, y);
    }
  }

  /**
   *  Append the rest of the skyline elements with indice (p, n)
   *  to the final output.
   */
  public void appendSkyline(List<List<Integer>> output, List<List<Integer>> skyline,
                            int p, int n, int currY) {
    while (p < n) {
      List<Integer> point = skyline.get(p);
      int x = point.get(0);
      int y = point.get(1);
      p++;

      // update output
      // if there is a skyline change
      if (currY != y) {
        updateOutput(output, x, y);
        currY = y;
      }
    }
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N \log N)$ ，其中 $N$ 是建筑物的数目。这个问题满足 [主定理情况II](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)
 ： $T(N) = 2 T(\frac{N}{2}) + 2N$ ，求解结果是 $\mathcal{O}(N \log N)$ 的时间复杂度。
* 空间复杂度：$\mathcal{O}(N)$ 。需要额外 $O(n)$ 的空间来保存结果。
