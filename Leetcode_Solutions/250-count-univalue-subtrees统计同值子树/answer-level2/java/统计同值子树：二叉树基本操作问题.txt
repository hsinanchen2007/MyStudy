### 基本思路
要统计同值子树，同值子树的定义：子树的所有节点都拥有相同的数值。
所以就有以下几种基本情况
1. 对应叶子节点来说一定是同值子树
2. 对于非叶子节点来说：
    1. 左子树是否为同值子树：
        1. 同值子树：左子树的值是否等于当前根节点的值
        2. 非同值子树：当前节点非同值子树
    2. 右子树是否为同值子树
        1. 同值子树：如果左子树也为同值，那么看下 root.val == left.val == right.val, 那么当前节点也为同值
        2. 非同值子树：当前节点非同值子树
所以对于每个节点我们要记录：
1. 子树是否是同值子树
2. 子树中同值子树的个数
```
public int countUnivalSubtrees(TreeNode root) {
        Res res = helper(root);
        return res.count;
    }

class Res {
    /// 当前节点下同值子树节点个数
    int count;
    /// 当前节点是否是同值子树
    boolean isUnivalSubtrees;
    public Res(int count, boolean isUnivalSubtrees) {
        this.count = count;
        this.isUnivalSubtrees = isUnivalSubtrees;
    }
}

private Res helper(TreeNode root) {
    /// null
    if (root == null) {
        return new Res(0, true);
    }
    /// 叶子节点
    if (root.left == null && root.right == null) {
        return new Res(1, true);
    }
    Res leftRes = helper(root.left);
    Res rightRes = helper(root.right);
    /// 左右子树非空
    if (root.left != null && root.right != null) {
        /// 如果左右子树都为非空子树：判断 left.value == right.value == root.value
        if (leftRes.isUnivalSubtrees && rightRes.isUnivalSubtrees && root.left.val == root.val && root.val == root.right.val ) {
            return new Res(leftRes.count + rightRes.count + 1,  true);
        } else {
            /// 当前节点不是同值子树，那么该节点下同值子树节点个数为左右同值子树节点个数之和
            return new Res(leftRes.count + rightRes.count, false);
        }
    } else if (root.left != null ){
        /// 左子树为非空子树，left.value == root.value
        if (leftRes.isUnivalSubtrees && root.left.val == root.val) {
            /// 该节点同值子树，节点个数为左子树中同值子树的节点个数 + 1
            return new Res(leftRes.count + 1,  true);
        } else {
            /// 该节点不是同值子树，节点个数为左子树中同值子树节点个数
            return new Res(leftRes.count, false);
        }
    } else {    /// 过程同左子树
        if (rightRes.isUnivalSubtrees && root.right.val == root.val) {
            return new Res(rightRes.count + 1,  true);
        } else {
            return new Res(rightRes.count,  false);
        }
    }
}
```