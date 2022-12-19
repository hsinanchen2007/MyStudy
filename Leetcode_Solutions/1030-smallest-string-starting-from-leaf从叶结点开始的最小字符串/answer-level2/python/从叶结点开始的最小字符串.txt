#### 方法：暴力法

**思路**

让我们创建出所有可能的字符串，然后逐一比较，输出字典序最小的那个。

**算法**

在我们深度优先搜索的过程中，我们不断调整 `sb`（或者 Python 代码中的 `A`），即根到这个节点的路径上的字符串内容。

当我们到达一个叶子节点的时候，我们翻转路径的字符串内容来创建一个候选答案。如果候选答案比当前答案要优秀，那么我们更新答案。

```java [deze3qTk-Java]
class Solution {
    String ans = "~";
    public String smallestFromLeaf(TreeNode root) {
        dfs(root, new StringBuilder());
        return ans;
    }

    public void dfs(TreeNode node, StringBuilder sb) {
        if (node == null) return;
        sb.append((char)('a' + node.val));

        if (node.left == null && node.right == null) {
            sb.reverse();
            String S = sb.toString();
            sb.reverse();

            if (S.compareTo(ans) < 0)
                ans = S;
        }

        dfs(node.left, sb);
        dfs(node.right, sb);
        sb.deleteCharAt(sb.length() - 1);
    }
}
```
```python [deze3qTk-Python]
class Solution(object):
    def smallestFromLeaf(self, root):
        self.ans = "~"

        def dfs(node, A):
            if node:
                A.append(chr(node.val + ord('a')))
                if not node.left and not node.right:
                    self.ans = min(self.ans, "".join(reversed(A)))

                dfs(node.left, A)
                dfs(node.right, A)
                A.pop()

        dfs(root, [])
        return self.ans
```


**复杂度分析**

* 时间复杂度：我们用 $O(N)$ 遍历这棵树，然后调整字符串内容 `A` [Python] 或者 `sb`。然后，翻转与比较的时间复杂度为 $O(L)$，其中 $L$ 是到达叶节点时候得到字符串的长度。例如，对于完全平衡的树，$L = \log N$ 且时间复杂度为 $O(N \log N)$。

* 空间复杂度：$O(N)$。



