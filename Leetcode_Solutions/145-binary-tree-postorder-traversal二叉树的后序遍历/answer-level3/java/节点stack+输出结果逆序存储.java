### 解题思路
https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/yong-stackflaglai-fang-zhi-jie-dian-by-hongan/
这是采用回溯思路的stack存储。
看了官方的做法，很有启发。
如果遍历的结果，以逆序的方式存储，那么访问的就不用回溯了。

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
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> output = new LinkedList<Integer>();

        if(root ==null){
            return output;
        }

        LinkedList<TreeNode> stack = new LinkedList<TreeNode>();
        stack.addLast(root);
        TreeNode curNode;
        while(!stack.isEmpty()){
            curNode = stack.pollLast();
            output.addFirst(curNode.val);//visit

            if(curNode.left!=null){
                stack.addLast(curNode.left);
            }

            if(curNode.right!=null){
                stack.addLast(curNode.right);
            }
        }

        return output;
    }
}

```