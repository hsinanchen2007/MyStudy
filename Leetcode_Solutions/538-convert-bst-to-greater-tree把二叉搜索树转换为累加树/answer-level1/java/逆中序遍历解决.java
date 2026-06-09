方法1![image.png](https://pic.leetcode-cn.com/5b4d9bb9116b37147470684b1a93784ba9614ecb749ded0524ae01cb7cbf88d9-image.png)

```
class Solution {
    int sum=0;
    public TreeNode convertBST(TreeNode root) {
        if(root==null){
            return null;
        }
        convertBST(root.right);
        root.val=root.val+sum;
        sum=root.val;
        convertBST(root.left);
        return root;
    }
}
```

方法2： ![image.png](https://pic.leetcode-cn.com/238a8177eabf571b2f94f030388183b0e0e7375dd88c90a71bce414ba52e6613-image.png)

```
class Solution {
    int sum=0;
    public TreeNode convertBST(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        TreeNode node=root;
        while(!stack.isEmpty()||node!=null){
            while(node!=null){
                stack.push(node);
                node=node.right;
            }
            node=stack.pop();
            sum+=node.val;
            node.val=sum;
            node=node.left;
        }
        return root;
    }
}
```