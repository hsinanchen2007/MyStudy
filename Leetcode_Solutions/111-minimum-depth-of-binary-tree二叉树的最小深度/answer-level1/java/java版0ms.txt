### 解题思路
利用双端队列。
在遍历节点时，只要遇到左右节点都为空的节点，那么此节点必然为叶节点。那么最小深度就是从根节点到第一个左右节点都为空的节点深度。

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
            int hight=1;
            Deque<TreeNode> queue=new LinkedList<TreeNode>();
            queue.add(root);
            TreeNode levleLast=root;
            while(!queue.isEmpty()){
                TreeNode node=queue.poll();
                if(node.left==null&&node.right==null) {
                    break;
                }
                if(node.left!=null) queue.add(node.left);
                if(node.right!=null) queue.add(node.right);
                    if(levleLast==node){
                        levleLast=queue.peekLast();
                        hight++;
                    }
}
            return hight;

}
}
```