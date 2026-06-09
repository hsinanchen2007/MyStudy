### 解题思路
1 利用定义的类，来记录遍历过的二叉树的深度。
2 把每次遍历的节点加入栈中。
3 每次遍历的叶子结点的时候更新最小深度

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
    public int minDepth(TreeNode root) {
            if(root==null) return 0;
            Stack<Record> stack=new Stack<Record>();
            stack.add(new Record(1,root));
            int minDepth=Integer.MAX_VALUE;
            while(!stack.isEmpty()){
                Record record=stack.pop();
                TreeNode node=record.node;
                int h=record.hight;
                if(node.left==null&&node.right==null) minDepth=Math.min(h,minDepth);
                if(node.left!=null) stack.add(new Record(h+1,node.left));
                if(node.right!=null) stack.add(new Record(h+1,node.right));
            }
            return minDepth;
    }

}
class Record{
    public int hight;
    public TreeNode node;
    public Record(int hight,TreeNode node){
        this.hight=hight;
        this.node=node;
    }
}
```