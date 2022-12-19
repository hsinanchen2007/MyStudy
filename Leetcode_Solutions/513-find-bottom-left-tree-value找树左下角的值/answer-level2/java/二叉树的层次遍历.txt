### 解题思路
这道题实际上就是二叉树的层次遍历。每一轮队列中的元素都是同一层的元素。最后一轮就是最后一层的元素；
然后第一个元素就是最后一层最左边元素。

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
    //传统的二叉树层次遍历没有第二个while循环。
    //这个队列中每一次经过外层循环的时候，队列中的元素都是同一层的元素。
    //然后将队列的第一个元素赋值给ans就可以了。
    public int findBottomLeftValue(TreeNode root) {
        if(root == null)
            return -1;

        int ans = root.val;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<TreeNode> list = new ArrayList<TreeNode>();
        queue.offer(root);

        while(!queue.isEmpty()){
            ans = queue.peek().val;
            
            while(!queue.isEmpty()){
                list.add(queue.poll());
            }
            while(list.size() != 0){
                TreeNode node = list.get(0);
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
                list.remove(0);
            }
        }
        return ans;
    }
}
```