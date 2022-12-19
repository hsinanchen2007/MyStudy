## 解析
以前序遍历的方式递归的检查每一个节点是否满足平衡二叉树的定义
## 代码
```java
public boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        if(Math.abs(dep(root.left) - dep(root.right))>1){
            return false;
        }
        return isBalanced(root.left)&&isBalanced(root.right);

    }

    private int dep(TreeNode root){
        if(root == null){
            return 0;
        }
        return Math.max(dep(root.left),dep(root.right))+1;
    }
```
