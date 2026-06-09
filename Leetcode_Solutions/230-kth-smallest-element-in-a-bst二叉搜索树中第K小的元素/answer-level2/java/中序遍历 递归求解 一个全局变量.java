```
/*  执行用时 : 1 ms, 在所有 Java 提交中击败了99.76%的用户
    内存消耗 : 40.3 MB, 在所有 Java 提交中击败了33.17%的用户*/
class Solution {
    // 记录（中序）遍历过的结点的数量，初始值为0
    private int count = 0;
    
    public int kthSmallest(TreeNode root, int k) {
        // 入参判断，如果树为空，返回-1表示未找到
        if(root == null) {
            return -1;
        }
        // 先遍历左子树，即在左子树中查找
        int left = kthSmallest(root.left, k);
        // 如果在左子树中找到了
        if(left != -1) {
            // 返回左子树中第k小的值
            return left;
        }
        // 如果左子树中未找到，说明左子树的结点数小于k
        // 判段当前结点是否为第k个结点，同时遍历过的结点数字+1
        if(++count == k) {
            // 若当前结点为第k个结点，返回当前结点的值
            return root.val;
        }
        // 否则遍历右子树，取右子树中查找
        return kthSmallest(root.right, k);
    }
}

```
