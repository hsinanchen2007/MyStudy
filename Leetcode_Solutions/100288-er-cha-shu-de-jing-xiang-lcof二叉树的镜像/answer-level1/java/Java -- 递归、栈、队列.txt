所谓镜像就是交换二叉树中每一个节点的左右子树，从而形成与原二叉树镜像的效果。
所以目的是交换每个节点的左右子树，而递归、栈、队列都只是一种实现“找到每个节点”即遍历的方法。


1.递归实现
```
代码块
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null){
            return null;
        }
        TreeNode pnt=root.left;
        root.left=mirrorTree(root.right);
        root.right=mirrorTree(pnt);
        return root;
    }
}
```


2.栈实现--先序遍历
```
代码块
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null){
            return null;
        }
        Stack<TreeNode> st=new Stack<>();
        TreeNode pnt,left;
        st.push(root);
        while(! st.isEmpty()){
            pnt=st.pop();
            left=pnt.left;
            pnt.left=pnt.right;
            pnt.right=left;

            if(pnt.left != null)
                st.push(pnt.left);
            if(pnt.right != null)
                st.push(pnt.right);
        }
        return root;
    }
}
```





2.队列实现--层序遍历
    对取出的对手节点，交换其左右子树，并将非空的左右子结点入队。

```
代码块
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null){
            return null;
        }
        Queue<TreeNode> que=new LinkedList<TreeNode>();
        TreeNode pnt,left;
        que.add(root);
        while(! que.isEmpty()){
            pnt=que.poll();
            left=pnt.left;
            pnt.left=pnt.right;
            pnt.right=left;

            if(pnt.left != null)
                que.add(pnt.left);
            if(pnt.right != null)
                que.add(pnt.right);
        }
        return root;
    }
}
```
