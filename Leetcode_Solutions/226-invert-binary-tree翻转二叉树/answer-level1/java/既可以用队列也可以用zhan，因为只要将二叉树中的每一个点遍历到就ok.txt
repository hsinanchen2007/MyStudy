### 解题思路
此处撰写解题思路

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
    // public TreeNode invertTree(TreeNode root) {
    //     if(root == null) return null;
    //     LinkedList<TreeNode> queue = new LinkedList<>();
    //     queue.addLast(root);
    //     while(queue.size() != 0){
    //         TreeNode current = queue.removeFirst();
    //          TreeNode temp = current.left; //更不会在这里出现null.left这种情形
    //          current.left = current.right; 
    //          current.right = temp;
    //         if(current.left != null) queue.addLast(current.left); // 如果current.left  ==  null，就不加到队列中,所以队列中就没有null。
    //         if(current.right != null) queue.addLast(current.right);

    //     }
    //     return root;
    // }


    public TreeNode invertTree(TreeNode root) {
         if(root == null) return null;
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);
        while(queue.size() != 0){
            TreeNode current = queue.removeLast();
             TreeNode temp = current.left; 
             current.left = current.right; 
             current.right = temp;
            if(current.left != null) queue.addLast(current.left);
            if(current.right != null) queue.addLast(current.right);

        }
        return root;
    }
    

}
```