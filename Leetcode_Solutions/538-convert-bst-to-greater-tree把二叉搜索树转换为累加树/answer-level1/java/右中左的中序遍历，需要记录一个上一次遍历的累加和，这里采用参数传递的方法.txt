```
class Solution {//左中右是按从小到大的遍历，所以右中左遍历就是从大到小，因此右中左遍历，比例过程中不断的加上原来的数就行了。
    public TreeNode convertBST(TreeNode root) {
        search(root, 0);
        return root;
    }
    public int search(TreeNode root, int n) {
        if(root == null) 
            return n;
        int right_val = search(root.right, n);
        root.val += right_val; //右中左的中序遍历，所以相加的操作只用在中间做就行了，其他的就是把参数传递到下一层
        int left_val = search(root.left, root.val);
        return left_val;//这里是把左中右三个节点里最后一个遍历的左子节点的返回值，返回给下一层
    }
}
```