### 解题思路
因为是二叉搜索树，所以对二叉树进行中序遍历，得到的就是从小到大的排列顺序；
因为是放入的是栈空间，所以依次栈底的数最大，栈顶最小；
依次弹出第K个数，就是第K大的数

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
    Stack<Integer> stack = new Stack<>();
    public int kthLargest(TreeNode root, int k) {
        midPost(root);
        for(int i = 0; i < k-1; i++){
            stack.pop();
        }
        return stack.pop();
    }
    public void midPost(TreeNode node){
        if(node == null)
            return ;
        midPost(node.left);
        stack.push(node.val);
        midPost(node.right);
    }
}
```