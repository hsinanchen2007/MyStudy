执行用时 :16 ms, 在所有 java 提交中击败了99.15%的用户
内存消耗 :38.7 MB, 在所有 java 提交中击败了100.00%的用户

完全二叉树的特性，节点位置与数组下标映射关系：
若节点位置位k, 则lchild位置位2*k, rchild位置位2*k+1; (从1开始计算)

```
class CBTInserter {
    int size;
    TreeNode[] A;
    void traverse(TreeNode root,int k){
        if(root==null)return;
        A[k]=root;
        if(k>size){
            size=k;
        }
        traverse(root.left,k<<1);
        traverse(root.right,(k<<1) | 1);
    }
    public CBTInserter(TreeNode root) {
        A=new TreeNode[11004];
        size=0;
        traverse(root,1);
    }

    public int insert(int v) {
        A[++size]=new TreeNode(v);
        if(size%2 == 0){
            A[size/2].left=A[size];
        }
        else{
            A[size/2].right=A[size];
        }
        return A[size/2].val;
    }

    public TreeNode get_root() {
        return A[1];
    }
}
```
