# 解题思路
根据二叉搜索树的特性，使用中序遍历到的第K个元素就是第K小的元素，在迭代过程中判断栈容量进行剪枝。

此处使用栈存储遍历到的节点，根据栈的特性，最后一个添加的元素在栈顶，所以遍历完直接弹栈即可。

平均时间复杂度O(K)，极端情况下会退化为O(n)，空间复杂度O(K)

# 代码
```
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<>();
        helper(root,k,stack);
        //栈顶元素就是第K小元素，直接弹栈即可
        return stack.pop().val;
    }

    private void helper(TreeNode root, int k,Stack<TreeNode> stack){
        //剪枝
        if(root == null || stack.size() == k) return;
        helper(root.left,k,stack);
        //处理完左子树，剪枝判断
        if(stack.size() == k) return;
        stack.push(root);
        helper(root.right,k,stack);
    }
}
```
