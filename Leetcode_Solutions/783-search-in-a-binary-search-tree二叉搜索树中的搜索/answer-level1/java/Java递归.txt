输出不是数组，所以不用去记录节点，只需返回根节点实例
即找到值相等的节点，将其输出
BST就用左右子树递归法
```java
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root != null) {
            
            if (root.val == val) 
                return root;
            
            else if (root.val > val) 
                return searchBST(root.left, val);
            
            else if (root.val < val) 
                return searchBST(root.right, val);
        }
        return null;
    }
}
```

结果看起来没有完整的数组输出，其实更简单