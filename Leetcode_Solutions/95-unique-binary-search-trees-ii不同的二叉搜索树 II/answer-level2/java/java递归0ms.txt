### 解题思路
从2开始每次从小到大依次插入每个数字，即每次插入的数字均为当前树中最大的数
因此每次插入只有两种方式：
1，将整个树作为新节点的左节点
2，从根节点开始向右遍历，对路径上的每个节点都可以将该节点的右节点设为新节点的左节点，并将新节点作为当前节点的右节点

### 代码

```java
/*
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode head;
    public List<TreeNode> generateTrees(int n) {
        if(n<=0) return new ArrayList<TreeNode>();
        head=new TreeNode(1);
        List<TreeNode> res=new ArrayList<TreeNode>();
        generateTrees(res,head,2,n);
        return res;
    }
    private void generateTrees(List<TreeNode> res, TreeNode head, int n, int m){
        if(n>m){
            TreeNode element=new TreeNode(head.val);
            copy(head,element);
            res.add(element);
            return;
        }
        TreeNode temp=head;
        TreeNode node=new TreeNode(n);
        node.left=head;
        generateTrees(res,node,n+1,m);
        while(temp!=null){
            node.left=temp.right;
            temp.right=node;
            generateTrees(res,head,n+1,m);
            temp.right=node.left;
            temp=temp.right;
        }
    }
    //复制一个新的二叉树
    private void copy(TreeNode head, TreeNode empty){
        if(head.left!=null){
            empty.left=new TreeNode(head.left.val);
            copy(head.left,empty.left);
        }
        if(head.right!=null){
            empty.right=new TreeNode(head.right.val);
            copy(head.right,empty.right);
        }
    }
}
```