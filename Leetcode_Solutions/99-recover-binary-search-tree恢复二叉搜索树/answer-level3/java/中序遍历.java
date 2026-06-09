利用二叉搜索树的中序遍历结果为递增，找到遍历结果中需要交换的两个节点；

二叉搜索树中如果只有两个节点被交换，那么遍历结果中顺序错位的节点，最多有两对：
分别定义为n1,n2,n3,n4；
其中n2 == n3，只需要把n1和n4进行交换；

再优化一下，分别定义为n1,n2,n3;
那么只需要把n1,n3交换；

再优化一下，实际上n2没有特别的用途，可以省略：
只定义n1，n2，n1为第一对的第一个元素，n2为第二对或第一对的第二个元素；


```
public void recoverTree(TreeNode root) {
        
        Stack<TreeNode> stack = new Stack<TreeNode>();
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
        
        TreeNode n1 = null; TreeNode n2 = null;
        TreeNode pre = stack.peek();
        
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            
            if (pre.val > node.val) {
                if (n1 == null) {
                    n1 = pre;
                } 
                n2 = node;
            }
            
            pre = node;
            TreeNode right = node.right;
            while (right != null) {
                stack.push(right);
                right = right.left;
            }
        }
        
        int v = n1.val;
        n1.val = n2.val;
        n2.val = v;

    }
```
