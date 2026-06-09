### 解题思路
注释和代码已经写的很清楚了，请参考

### 代码

```java
class Solution {
    // 解题思路，就是根据前序遍历和中序遍历的交集，来确定元素的顺序
    // 比如题目中的例子
    // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    // 第一步，我们可以确定，在preorder中，root = 3
    // 那么，既然元素是不重复的，那么在中序遍历中，3就是root，3的左边是left子树，3的右边是right子树
    // preorder = [3,9,20,15,7]
    //             ^---------------这是根
    // inorder = [9,3,15,20,7]
    // 这是左树----^ ^  ^-----------这是右子树
    // 构造树
    //            3
    //           / \
    //          9  15,20,7
    // 然后再看剩下的数组 preorder=[20, 15, 7], inorder=[15, 20, 7]
    // 同理可知，根是20，left=15，right=7
    //            3
    //           / \
    //          9  20
    //             / \
    //            15  7
    int pre_idx = 0;
    int[] preorder;
    int[] inorder;
    Map<Integer, Integer> idx_map = new HashMap<Integer, Integer>();

    public TreeNode helper(int in_left, int in_right) {
        // 如果左侧的数组脚标和右侧的数组脚标已经碰撞了
        // 接结束，返回一个NULL节点
        if (in_left == in_right)
            return null;

        // 先从前序遍历的数组中找到根（肯定是第一个元素，0脚标）
        int root_val = preorder[pre_idx];
        // 构建根
        TreeNode root = new TreeNode(root_val);

        // 在中序遍历的数组中找到根所在的位置
        // 这个位置左侧的元素都是左子树
        // 这个位置右侧的元素都是右子树
        int index = idx_map.get(root_val);

        // 将前序遍历数组的根元素往后挪动一个位置
        // 前序遍历每次去掉1个元素剩下的就都是根
        pre_idx++;
        // 构建左子树
        root.left = helper(in_left, index);
        // 构建右子树
        root.right = helper(index + 1, in_right);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.inorder = inorder;

        // 定做一个哈希表
        // 以中序遍历数组为基础
        // 为的是后面找中序的元素方便
        int idx = 0;
        for (Integer val : inorder)
            idx_map.put(val, idx++);
        return helper(0, inorder.length);
    }
}
```