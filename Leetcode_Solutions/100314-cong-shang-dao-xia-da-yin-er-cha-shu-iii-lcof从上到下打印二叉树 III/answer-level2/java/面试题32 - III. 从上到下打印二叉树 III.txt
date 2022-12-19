### 解题思路
正序加入，逆序加入交替进行

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<Integer> lsroot = new ArrayList<>();
        List<List<Integer>> ls = new ArrayList<List<Integer>>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();

        if(root==null){
            return ls;
        }

        
        lsroot.add(root.val);
        ls.add(lsroot);
        queue.add(root);
        int dir=0;
        while (!queue.isEmpty()) {

            List<Integer> tmp = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {

                TreeNode node = queue.poll();

                if (node.left != null) {
                    tmp.add(node.left.val);
                    queue.add(node.left);
                }
                if (node.right != null) {
                    tmp.add(node.right.val);
                    queue.add(node.right);
                }
            }
            if (!tmp.isEmpty()) {
                if (dir == 1) {
                    ls.add(tmp);
                    dir = 0;
                } else {
                    Collections.reverse(tmp);
                    ls.add(tmp);
                    dir = 1;
                }
            }

            
        }
        System.out.println(ls);
        return ls;
    }
}
```