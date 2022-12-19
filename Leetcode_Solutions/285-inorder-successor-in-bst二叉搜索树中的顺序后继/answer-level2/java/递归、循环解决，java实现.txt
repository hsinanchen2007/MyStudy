方法1：递归执行中序遍历，获取list，得到p的下一个。时间O(N)，空间O(N)

方法2：
递归执行中序遍历，在递归过程中获取x的下一个。如果当前值是<=x的，那么根据BST的特性只需要在右子树中找。如果当前值>x，则当前值有可能，它的左子树也有可能有更小的但是也>x的，对左子递归后，选择更接近的（更小的).
时间O(logN)，空间O(logN)调用栈的深度。
```java
public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    if(p==null||root==null){
        return null;
    }
    if(root.val<=p.val){//当前和左边都不可能>p
        return inorderSuccessor(root.right,p);
    }
    //root>p
    TreeNode res1=inorderSuccessor(root.left,p);
    if(res1!=null&&res1.val<root.val){
        return res1;
    }else{
        return root;
    }
}
```

方法3：循环实现
如果当前值是<=x的，那么根据BST的特性只需要在右子树中找：cur=cur.right。
如果当前值>x，则当前值有可能，它的左子树也有可能有更小的但是也>x的。则每次走入这个分支时，当前点是一个候选点，记录该节点的值和历史最小节点的值。
时间O(logN)，空间O(1）
```java
public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    if(p==null||root==null){
        return null;
    }
    TreeNode cur=root;
    TreeNode res=null;
    while(cur!=null){
        if(cur.val<=p.val){
            cur=cur.right;
        }else{
            if(res==null||res.val>cur.val){
                res=cur;
            }
            cur=cur.left;
        }
    }
    return res;
}
```