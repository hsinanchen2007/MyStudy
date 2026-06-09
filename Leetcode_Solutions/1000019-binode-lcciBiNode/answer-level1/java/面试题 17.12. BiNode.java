### 解题思路
内存一直超限,是因为自己没有把最后一个节点的left置为NULL；

```
 node.left=null;//pre.left=null;
 pre.right=node;
 pre=node;
 node = node.right;
```

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode convertBiNode(TreeNode root) {
        /*
        题目分析
        left置空，right为下一链表结点
        值的顺序不变 转换操作原值，在原始的二叉树上直接修改

        二叉搜索树的特点
        左节点值要小于根再小于右节点  所以应采用中序遍历 左 根  右
        如果使用递归遍历，无法对结点的值进行保存和修改
         
        所以这里尝试使用循环遍历
        */
        if(root==null){
            return root;
        }
        TreeNode pre=new TreeNode(0);
        TreeNode head=pre;
        TreeNode node=root;
        Deque<TreeNode> stack=new LinkedList<>();
        while(node!=null||!stack.isEmpty()){
            if(node!=null){
                stack.push(node);
                node=node.left;
            }else{
                node = stack.pop();

                node.left=null;
                //pre.left=null;
                pre.right=node;
                pre=node;
				node = node.right;
            }
        }
     
        return head.right;     
    }
}
```