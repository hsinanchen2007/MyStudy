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
class FindElements {
    private Queue<TreeNode> queue = new LinkedList<>();
    private List<Integer> list = new ArrayList<>();
    public FindElements(TreeNode root) {
        if (null == root) {
            return;
        }
        queue.add(root);
        list.add(0);
        int step =0;
        while (!queue.isEmpty()) {
            int length = queue.size();
            TreeNode node = queue.remove();
            if (node.left != null ){
                queue.add(node.left);
                list.add(2 * list.get(step) + 1);
            }
            if (node.right != null ){
                queue.add(node.right);
                list.add(2 * list.get(step) + 2);
            } 
            step++;
        }
    }
    
    public boolean find(int target) {
        for (Integer val : list) {
            if (val == target) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
```