### 解题思路
让每一个节点处理内部的转换关系。处理结束后，返回一个长度为`2`的数组，分别包含该子节点转换后的`最小值`和`最大值`的节点。

应该是目前最清晰的解题思路，时间复杂度 **O(N)**，空间复杂度 **O(logN)**。



### 代码

```java
class Solution {
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        Node[] nodes = convert(root);
        nodes[1].right = nodes[0];
        nodes[0].left = nodes[1];
        return nodes[0];
    }

    private Node[] convert(Node root) {
        Node[] ans = {root, root};

        if (root.left != null) {
            Node[] left = convert(root.left);
            root.left = left[1];
            left[1].right = root;
            ans[0] = left[0];
        }

        if (root.right != null) {
            Node[] right = convert(root.right);
            root.right = right[0];
            right[0].left = root;
            ans[1] = right[1];
        }

        return ans;
    }
}
```

执行用时: **0 ms** , 在所有 Java 提交中击败了 **100%** 的用户
内存消耗: **36 MB** , 在所有 Java 提交中击败了 **100%** 的用户