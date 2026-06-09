1、递归：用递归的思路更自然。采用树的先序遍历，定义好出口后由函数递归调用，逐层地求解每棵子树的值

```
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {

        if(t1==null)
            return t2;
        if (t2==null)
            return t1;
        TreeNode tree = new TreeNode( t1.val + t2.val );
        tree.val = t1.val + t2.val;
        tree.left = mergeTrees(t1.left, t2.left);
        tree.right = mergeTrees(t1.right, t2.right);
        return tree;

    }
}
```


2、迭代：利用一个堆栈，对需要进行计算的节点：将两棵树的位于同一位置的节点同时存入其中；若树2为空则跳过本次循环，保留树1的原始值；否则计算两者的和，作为当前值；若树1的子树为空，则将其复制为t2的对应子树，否则将两者的同一方向子树存入堆栈。

```
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        
        if (t1 ==null)
            return t2;
        Stack <TreeNode[]> stack = new Stack<TreeNode[]>();
        stack.push(new TreeNode[] {t1,t2});
        while(!stack.isEmpty())
        {
            TreeNode[] t = stack.pop();
            if( t[1]==null)            //如果t1为null
                continue;

            t[0].val = t[0].val + t[1].val;            //如果t0、t1都有树

            //以下代码：若t0的子树为空，则进行处理复制t1的值，保证其非空

            if (t[0].left==null)           //如果t0的左子树为空，复制t1
                t[0].left=t[1].left;
            else stack.push(new TreeNode[] { t[0].left , t[1].left } );   //入栈
            
            if (t[0].right == null)         //如果t0的右子树为空，复制t1
                t[0].right =t[1].right;
            else stack.push(new TreeNode[] { t[0].right , t[1].right } );
        }
        return t1;
    }
}
```

