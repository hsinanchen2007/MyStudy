####  方法一：记录坐标
明显的，该解决方案有两个步骤：首先，找出每个节点所在的坐标，然后报告他们的坐标。

**算法：**

我们可以使用深度优先搜索找到每个节点的坐标。保持当前节点 `(x, y)`，移动的过程中，坐标变化为 `(x-1, y+1)` 或 `(x+1, y+1)` 取决于是左孩子还是右孩子。

我们通过 `x` 坐标排序，再根据 `y` 坐标排序，这样确保以正确的顺序添加到答案中。

```python [solution1-Python]
class Solution(object):
    def verticalTraversal(self, root):
        seen = collections.defaultdict(
                  lambda: collections.defaultdict(list))

        def dfs(node, x=0, y=0):
            if node:
                seen[x][y].append(node)
                dfs(node.left, x-1, y+1)
                dfs(node.right, x+1, y+1)

        dfs(root)
        ans = []

        for x in sorted(seen):
            report = []
            for y in sorted(seen[x]):
                report.extend(sorted(node.val for node in seen[x][y]))
            ans.append(report)

        return ans
```

```java [solution1-Java]
class Solution {
    List<Location> locations;
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        // Each location is a node's x position, y position, and value
        locations = new ArrayList();
        dfs(root, 0, 0);
        Collections.sort(locations);

        List<List<Integer>> ans = new ArrayList();
        ans.add(new ArrayList<Integer>());

        int prev = locations.get(0).x;

        for (Location loc: locations) {
            // If the x value changed, it's part of a new report.
            if (loc.x != prev) {
                prev = loc.x;
                ans.add(new ArrayList<Integer>());
            }

            // We always add the node's value to the latest report.
            ans.get(ans.size() - 1).add(loc.val);
        }

        return ans;
    }

    public void dfs(TreeNode node, int x, int y) {
        if (node != null) {
            locations.add(new Location(x, y, node.val));
            dfs(node.left, x-1, y+1);
            dfs(node.right, x+1, y+1);
        }
    }
}

class Location implements Comparable<Location>{
    int x, y, val;
    Location(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }

    @Override
    public int compareTo(Location that) {
        if (this.x != that.x)
            return Integer.compare(this.x, that.x);
        else if (this.y != that.y)
            return Integer.compare(this.y, that.y);
        else
            return Integer.compare(this.val, that.val);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 指的是树的节点个数。
* 空间复杂度：$O(N)$。