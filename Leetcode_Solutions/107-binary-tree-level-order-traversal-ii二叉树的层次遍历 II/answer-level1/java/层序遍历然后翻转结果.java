### 解题思路
最基础的方案：先层序遍历，然后再翻转结果。高深的暂没有
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        List<List<Integer>> temp = new ArrayList<>();
        
        Queue<TreeNode> queue = new LinkedList<>();
        if (root!=null) queue.add(root);

        while (!queue.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            for (int i=queue.size();i>0;i--) {
                TreeNode tmp= queue.poll();

                list.add(tmp.val);
                if (tmp.left!=null) queue.add(tmp.left);
                if (tmp.right!=null) queue.add(tmp.right);
            }
            temp.add(list);
        }

        for (int i=temp.size()-1;i>=0;i--) {
            List<Integer> list = temp.get(i);
            res.add(list);
        }
        return res;
    }
}
```