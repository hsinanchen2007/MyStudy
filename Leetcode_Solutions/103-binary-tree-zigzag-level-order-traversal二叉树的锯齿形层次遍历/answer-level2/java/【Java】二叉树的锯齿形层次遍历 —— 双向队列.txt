首先使用一个队列进行普通的层次遍历，并使用映射来存储节点的深度，最后根据深度来判断是加入队首还是加入队尾，这样就无需翻转了。
时间复杂度O(n)，空间复杂度O(n)。
```java
import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        Map<TreeNode, Integer> map = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        map.put(root, 0);

        List<List<Integer>> ans = new ArrayList<>();
        LinkedList<Integer> ls = null;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            int depth = map.get(node);
            if (ans.size() <= depth) {
                ls = new LinkedList<>();
                ans.add(ls);
            }
            if (depth % 2 == 0) {
                ls.offerFirst(node.val);
            } else {
                ls.offerLast(node.val);
            }
            if (node.right != null) {
                map.put(node.right, depth + 1);
                queue.add(node.right);
            }
            if (node.left != null) {
                map.put(node.left, depth + 1);
                queue.add(node.left);
            }
        }
        return ans;
    }
}
```