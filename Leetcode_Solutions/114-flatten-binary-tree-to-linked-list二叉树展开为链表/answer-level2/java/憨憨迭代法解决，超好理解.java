![QQ截图20191126110614.png](https://pic.leetcode-cn.com/6b29bb91ffcfa9514126fae15c8bd309f28d1dd405f1499eefaa9ea7d5cdd859-QQ%E6%88%AA%E5%9B%BE20191126110614.png)

思路：迭代处理节点，如果左节点为空，则直接处理右节点，如果左节点不为空，需要把右节点递归放到左节点的最右叶子节点。
缺点是需要多次遍历左子树的高度，例如：

例如题目描述中给出的二叉树，需要遍历2→4，把root的右子树放到4的右子树。

     1
      \
       2
      / \
     3   4
          \
           5
            \
             6
```
public class FlattenTree {
    public void flatten(TreeNode root) {
        TreeNode temp = root;
        while(temp != null){
            if (temp.left != null) {
                TreeNode tempLeft = temp.left;
                TreeNode tempRight = null;
                if (temp.right != null) {
                    tempRight = temp.right;
                }
                temp.right = tempLeft;
                while (tempLeft.right != null) {
                    tempLeft = tempLeft.right;
                }
                tempLeft.right = tempRight;
                temp.left = null;
            }

            temp = temp.right;
        }
        return;
    }
}
```
