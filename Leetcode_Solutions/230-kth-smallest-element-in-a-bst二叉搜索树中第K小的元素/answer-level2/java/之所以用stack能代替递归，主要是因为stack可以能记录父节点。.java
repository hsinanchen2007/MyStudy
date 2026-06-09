### 解题思路
stack有个好处就是能够记录访问顺序，我们刚开始向左下遍历的时候，stack压入顺序是我们访问顺序一样，但是回溯的顺序正因为有了stack的先入后出的特性，所以才适合回溯。

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
    public int kthSmallest(TreeNode root, int k) {
        int i = 1;
        TreeNode node = null;
        TreeNode rootBak = root;
        LinkedList<TreeNode> stack = new LinkedList<TreeNode>();
        while(root != null){
            stack.addFirst(root);
            root = root.left;
        } 
        i = 0;
        
        while(i != k){
            node = stack.removeFirst();
            i++;
            if(i == k) break;
            if(node.right != null){// 有右边节点，有边界点的左边子节点不知道有多少个，要从最深的一个左边子节点开始。
                TreeNode tmp = node.right;
                // stack.addFirst(tmp);
                while(tmp != null){
                    stack.addFirst(tmp);
                    tmp = tmp.left;
                }
            }
        }
        return node.val;
    }
}
```