1. 常规的删除当前结点（cur)的方法是，找到他的父结点（pre），然后我们将pre指向cur结点的儿子结点（child），这样就完成了删除工作。用在本题呢显然是不够方便的。因为我们不知道pre结点是啥啊。所以我们的办法是，我们把cur结点变成child结点，我们继承child结点的val 左右结点，这样一来的话不就相当于删除了cur结点。
下面分享我的代码，请各位指点
```java
public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null)
            return null;
        if(key < root.val)
            root.left = deleteNode(root.left, key);
        if(key > root.val)
            root.right = deleteNode(root.right, key);
        if(root.val == key){
            TreeNode left = root.left;
            TreeNode right = root.right;
            if(left == null && right == null){
                root = null;
            }
            else {
                if (root.right == null) {
                    root.val = left.val;
                    root.right = left.right;
                    root.left = left.left;
                } else {
                    root.val = right.val;
                    root.left = right.left;
                    root.right = right.right;
                    deleteNode(left, key);
                    if(left != null){
                        TreeNode temp = root;
                        while(temp.left != null) temp = temp.left;
                        temp.left = left;
                    }
                }
            }
        }
        return root;
    }
```
