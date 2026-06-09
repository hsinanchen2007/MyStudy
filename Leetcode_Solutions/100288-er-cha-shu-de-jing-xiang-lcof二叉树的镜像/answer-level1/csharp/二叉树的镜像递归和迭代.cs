#### 思路1： 递归
即输入一个二叉树，他的镜像为自己的左右子树互换，同时左右子树也是镜像二叉树。递归终止条件就是root == null
##### 先分享一个自己三下五除二写的错误递归
```
public TreeNode MirrorTree(TreeNode root) {
        if(root == null)
        {
            return root;
        }
        //下面两行不应该这么写，因为首先改变了root.left，下面的MirrorTree(root.left)就不再是原先的root.left了。
        root.left = MirrorTree(root.right);
        root.right = MirrorTree(root.left);

        return root;
    }
```

##### 正确的递归写法
```
public TreeNode MirrorTree(TreeNode root) {
        if(root == null)
        {
            return root;
        }
        var left = MirrorTree(root.right);
        var right = MirrorTree(root.left);
        root.left = left;
        root.right = right;

        return root;
    }
```
#### 思路2 迭代
利用队列辅助进行迭代，先把节点的左右子树互换，然后将非空的左右子树推入队列中，循环至队列为空。
```
public TreeNode MirrorTree(TreeNode root) {
        if(root == null)
        {
            return root;
        }
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        while(queue.Count > 0)
        {
            var currentNode = queue.Dequeue();
            var tempLeftNode = currentNode.left;
            currentNode.left = currentNode.right;
            currentNode.right = tempLeftNode;

            if(currentNode.left != null)
            {
                queue.Enqueue(currentNode.left);
            }
            if(currentNode.right != null)
            {
                queue.Enqueue(currentNode.right);
            }
        }

        return root;
    }
```
