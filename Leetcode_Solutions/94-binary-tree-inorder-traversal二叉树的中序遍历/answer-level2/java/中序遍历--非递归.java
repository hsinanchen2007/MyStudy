递归的实现逻辑并不复杂，略过。

个人实现非递归思路：

```
public List<Integer> inorderTraversal(TreeNode root) {
        //结果集
        List<Integer> list = new ArrayList<>();
        
        if (root == null)
            return list;
        
        Stack<TreeNode> stack = new Stack<>();

        //一股脑地左子树递归入栈        
        while(root != null) {
            stack.push(root);
            root = root.left;
        }
        
        while(!stack.isEmpty()){
            TreeNode node = stack.pop();
            list.add(node.val);

            //右子树及右子树的左子树一股脑地入栈
            TreeNode right = node.right;            
            while(right != null) {
                stack.push(right);
                right = right.left; 
            }
        }
        
        return list;
    }
```

假设需要遍历的二叉树为如下:
```
    1
   /\
  2  5
 /\   \
3  4   6
```


对于这么一颗二叉树，非递归遍历入栈出栈过程：

```
stack的元素         push元素        pop元素
Empty               1
1                   2
1 2                 3
1 2 3                               3
1 2                                 2
1                   4               
1 4                                 4
1                                   1
Empty               5
5                                   5
Empty               6                 
6                                   6
Empty
```

`pop()`之后`visit()`元素，那么得到的结果集为`{3,2,4,1,5,6}`

从上面的入栈出栈过程，可以看出，如果在`push()`之后`visit()`元素，则得到先序遍历的结果`{1,2,3,4,5,6}`
