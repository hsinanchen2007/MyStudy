根据题目的意思，我们可以提出这样一种策略，那就是加一个判断条件，判断当前root的left子树和right子树是否符合要求，如果left子树有1，那么保留left子树，如果right子树有1，那么保留right子树
基于此，我们可以按照如下方式来展开代码：

(1)如果当前节点为null，那么我们返回什么？其实可以这么理解，如果当前节点为null，我们遇到了1，肯定返回true，所以一路顺畅到了叶节点，那就说明这条路上没有一个1，所以我们返回false；
(2)获取left子树是否包含1，获取right子树是否包含1;
(3)如果相应子树不包含1(返回值为false)，那么我们就置root.left = null或者 root.right = null;
(4)当前root对应的也可能是上一个节点的子树，所以返回结果为 root.val == 1 || needLeft || needRight; 

```
    public TreeNode pruneTree(TreeNode root) {
        if(needSubTree(root)) return root;
        else return null;
    }

    private boolean needSubTree(TreeNode root){
        if(root == null) return false;

        boolean needLeft = needSubTree(root.left);
        boolean needRight = needSubTree(root.right);

        if(!needLeft) root.left = null;
        if(!needRight) root.right = null;

        return root.val == 1 || needLeft || needRight; 
    }
```
