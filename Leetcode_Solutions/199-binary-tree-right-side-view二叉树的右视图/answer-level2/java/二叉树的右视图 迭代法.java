

## 思路分析
类似于 《二叉树的层次遍历》，保存每一层的最右边的节点的值即可。

时间复杂度O(N)，空间复制度O(N)，用了一个队列临时维护每一层的节点，最坏情况下二叉树是满节点，维护的节点数是最后一层的个数。

## 代码实现
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Queue<TreeNode> temp = new LinkedList<>();
        temp.add(root);
        while(!temp.isEmpty()){
            TreeNode face=null;
            Queue<TreeNode> queue = new LinkedList<>();
            while(!temp.isEmpty()){
                TreeNode node = temp.poll();
                if(node==null) continue;
                face = node;
                queue.add(face.left);
                queue.add(face.right);
            }
            if(face!=null) result.add(face.val);
            temp.addAll(queue);
        }
        return result;
    }
}
```