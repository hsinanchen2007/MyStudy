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
    private Deque<TreeNode> deque;

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList <> ();
        deque = new LinkedList <> ();
        if (root==null){
            return res;
        }else{
            deque.offer (root);
            List<Integer> temp = null;
            while (!deque.isEmpty ()){
                int size = deque.size ();
                temp = new ArrayList <> ();
                for(int i=0;i <size;i++){
                    TreeNode tempNode = deque.poll ();
                    temp.add (tempNode.val);
                    if (tempNode.left!=null) deque.offer (tempNode.left);
                    if (tempNode.right!=null) deque.offer (tempNode.right);
                }
                res.add (temp);
            }
        }
        return res;
    }
}
```