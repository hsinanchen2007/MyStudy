####  方法一：动态规划
我们尝试覆盖每个节点，从树的顶部开始向下。所考虑的每个节点都必须由该节点或某个邻居的摄像机覆盖。

**算法：**

让 `solve(node)` 函数提供一些信息，说明在不同的状态下，需要多少摄像机才能覆盖此节点的子树。基本上有三种状态:
- [状态 0]：森严的子树：该节点下的所有节点都被覆盖，但不包括该节点。
- [状态 1]：正常的子树：该节点下的所有节点和该节点均被覆盖，但是该节点没有摄像头。
- [状态 2]：放置摄像头：该节点和子树均被覆盖，且该节点有摄像头。

一旦我们用这种方式来界定问题，答案就明显了：
- 若要满足森严的子树，此节点的孩子节点必须处于状态 1。
- 若要满足正常的子树，此节点的孩子节点必须在状态 1 或 2，其中至少有一个孩子在状态 2。
- 若该节点放置了摄像头，则它的孩子节点可以在任一的状态。

```python [solution1-Python]
class Solution(object):
    def minCameraCover(self, root):
        def solve(node):
            # 0: Strict ST; All nodes below this are covered, but not this one
            # 1: Normal ST; All nodes below and incl this are covered - no camera
            # 2: Placed camera; All nodes below this are covered, plus camera here

            if not node: return 0, 0, float('inf')
            L = solve(node.left)
            R = solve(node.right)

            dp0 = L[1] + R[1]
            dp1 = min(L[2] + min(R[1:]), R[2] + min(L[1:]))
            dp2 = 1 + min(L) + min(R)

            return dp0, dp1, dp2

        return min(solve(root)[1:])
```

```java [solution1-Java]
class Solution {
    public int minCameraCover(TreeNode root) {
        int[] ans = solve(root);
        return Math.min(ans[1], ans[2]);
    }

    // 0: Strict ST; All nodes below this are covered, but not this one
    // 1: Normal ST; All nodes below and incl this are covered - no camera
    // 2: Placed camera; All nodes below this are covered, plus camera here
    public int[] solve(TreeNode node) {
        if (node == null)
            return new int[]{0, 0, 99999};

        int[] L = solve(node.left);
        int[] R = solve(node.right);
        int mL12 = Math.min(L[1], L[2]);
        int mR12 = Math.min(R[1], R[2]);

        int d0 = L[1] + R[1];
        int d1 = Math.min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + Math.min(L[0], mL12) + Math.min(R[0], mR12);
        return new int[]{d0, d1, d2};
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 指的是树中的节点数。
* 空间复杂度：$O(H)$，其中 $H$ 指的是树的高度。


####  方法二：贪心算法
于其试图从上到下覆盖每个节点，不如尝试从上到下覆盖它--考虑新放置一个具有最深节点的相机，a年后沿着树向上移动。

如果节点的子节点被覆盖，且该节点具有父节点，则最好的情况是将摄像机放置在父节点上。

**算法：**

如果一个节点有孩子节点且没有被摄像机覆盖，则我们需要放置一个摄像机在该节点。此外，如果一个节点没有父节点且没有被覆盖，则必须放置一个摄像机在该节点。

```python [solution2-Python]
class Solution(object):
    def minCameraCover(self, root):
        self.ans = 0
        covered = {None}

        def dfs(node, par = None):
            if node:
                dfs(node.left, node)
                dfs(node.right, node)

                if (par is None and node not in covered or
                        node.left not in covered or node.right not in covered):
                    self.ans += 1
                    covered.update({node, par, node.left, node.right})

        dfs(root)
        return self.ans
```

```java [solution2-Java]
class Solution {
    int ans;
    Set<TreeNode> covered;
    public int minCameraCover(TreeNode root) {
        ans = 0;
        covered = new HashSet();
        covered.add(null);

        dfs(root, null);
        return ans;
    }

    public void dfs(TreeNode node, TreeNode par) {
        if (node != null) {
            dfs(node.left, node);
            dfs(node.right, node);

            if (par == null && !covered.contains(node) ||
                    !covered.contains(node.left) ||
                    !covered.contains(node.right)) {
                ans++;
                covered.add(node);
                covered.add(par);
                covered.add(node.left);
                covered.add(node.right);
            }
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 指的是树中的节点数。
* 空间复杂度：$O(H)$，其中 $H$ 指的是树的高度。