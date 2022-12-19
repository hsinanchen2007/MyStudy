主要思路：
	1) 取出栈顶元素（需将整棵树放入到栈中）
		a. 将root的值放入到list中。
		b. 将右子树放入到栈中。
		c. 将左子树作为整体考虑，重复此过程，直至左子树为空。
	2) 重复1）操作，直至栈为空

图解如下：


![二叉树前序遍历.png](https://pic.leetcode-cn.com/047dbe9b3236689cb7214c741c38c9c9abe63b6e810c32ec0541f5eb60275ab6-%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86.png)


代码片段：
```
	public List<Integer> preorderTraversal(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();   //用于存放右子树
        ArrayList<Integer> list = new ArrayList<>();
        if(root == null) 
            return list;
        
        st.push(root);
        
        while(!st.isEmpty()){
            TreeNode tree = st.pop();
            while(tree != null){
                list.add(tree.val);
                if(tree.right != null)
                    st.push(tree.right);
                tree = tree.left;
            }
        }
        
        return list;        
        
    }
```

