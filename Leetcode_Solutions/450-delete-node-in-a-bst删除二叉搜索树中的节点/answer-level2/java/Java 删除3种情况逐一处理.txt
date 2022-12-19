与官方不同的地方在于处理只有一个子节点时，与存在的节点交换数据。

###
基本情况：node == null ，寻找结束

递推关系：
如果 key = node.val 表示找到要删除的节点，否则根据比值继续左右寻找。
找到 node 后有三种情况：
1. node 是叶子节点直接返回 null
2. node 是仅存在一个子节点时，与存在的节点交换数据
3. node 存在左右子树时，我们可以找他的前驱或者后继节点，该处代码实现寻找后继。找到后继节点后更新值，然后删除后继节点

 思考：此题需要返回根节点，所以递归函数的返回值需要在返回后计算(.left .right)

### 代码

```java
class Solution {

    public TreeNode deleteNode(TreeNode node, int key) {
        if (node == null) return null;
        if (key > node.val) { // 向右找
            node.right = deleteNode(node.right, key);
        } else if (key < node.val) { // 向左找
            node.left = deleteNode(node.left, key);
        } else { // 找到删除节点处理
            return eqHelper(node);
        }
        return node;
    }

    // 找到删除节点的处理逻辑
    private TreeNode eqHelper(TreeNode node) {
        boolean leftNull = node.left == null;
        boolean rightNull = node.right == null;
        if (leftNull && rightNull) { // 1.删除的是叶子节点
            return null;
        } else if (leftNull || rightNull) { // 2.删除的是只有一个子节点的节点
            TreeNode replace = leftNull ? node.right : node.left;
            node.val = replace.val;
            node.left = replace.left;
            node.right = replace.right;
            return node;
        } else { // 3.删除的是含有两个子节点的节点
            TreeNode right = node.right; // 要寻找后继节点的主节点
            TreeNode replace = right; // 后继节点
            while (replace.left != null) { // 寻找后驱节点
                replace = replace.left;
            }
            node.val = replace.val; // 当前值更新为后继节点的值
            node.right = deleteNode(right, node.val); // 删除后继节点
            return node;
        }
    }
}
```