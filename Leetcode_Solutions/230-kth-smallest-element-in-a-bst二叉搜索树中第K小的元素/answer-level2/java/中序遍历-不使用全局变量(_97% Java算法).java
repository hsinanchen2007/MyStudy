1. 二叉搜索树，其第K小的元素就是中序遍历的第K个Node，故这道题的本质就是是中序遍历。
2. 在整个遍历过程中需要保存遍历到了第几个，如果为第K个，则可以返回该值
3. 利用Java的包装类来保存结果



```Java
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        int[] mark = new int[1];
        mark[0] = 0;
        
        return visit(root, k, mark);
    }
    
    private Integer visit(TreeNode node, int k, int[] mark) {
        if (node == null) return null;
        
        Integer left = visit(node.left, k, mark);
        if (left != null) return left;
        
        mark[0]++;
        if (mark[0] == k) return node.val;
        
        Integer right = visit(node.right, k, mark);
        if (right != null) return right;
        
        return null;
    }
}
```

