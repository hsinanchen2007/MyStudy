### 解题思路
比较原始，使用队列，入队时判断是否存在，遍历该层元素时需要保存当前队列长度。
```java
Queue<TreeNode> queue = new LinkedList<TreeNode>();
```


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
        List<List<Integer>> ls = new ArrayList<List<Integer>>();
        if(root==null)
            return ls;

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        
        List<Integer> lsroot = new ArrayList<>();
        lsroot.add(root.val);
        ls.add(lsroot);
        queue.add(root);

        while (!queue.isEmpty()) {
            List<Integer> tmp = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {//遍历该层元素

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
            if (!tmp.isEmpty())
                ls.add(tmp);
        }
        //System.out.println(ls);
        return ls;

    
    }
}
```