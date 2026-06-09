### 解题思路
依旧是借助于队列实现层次遍历，只是在遍历过程中需要记录当前行的元素数目，以及记录下一行的元素数目。
每一层是一个单独的list结果，在遍历某一层开始时则创建一个！！！
Note：最后一层处理完之后，队列非空，此时遍历时list将会是一个空，因此最后需要检查添加的list是否size为0，为0则知道遍历到最后一行了。

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
        if (root == null) {
            return new ArrayList<>();
        }

        // 首先将root这一层初始化并放入结果集合中
        List<List<Integer>> results = new ArrayList<>();
        List<Integer> list = new ArrayList<Integer>();
        list.add(root.val);
        results.add(list);

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        int cur = 1;
        int next = 0;

        while (!queue.isEmpty()) {
            List<Integer> tmpList = new ArrayList<Integer>();
            for (int i = 0; i < cur; i++) {
                TreeNode tmp = queue.poll();
                if (tmp.left != null) {
                    queue.offer(tmp.left);
                    next++;
                    tmpList.add(tmp.left.val);
                }
                if (tmp.right != null) {
                    queue.offer(tmp.right);
                    next++;
                    tmpList.add(tmp.right.val);
                }
            }

            cur = next;
            next = 0;
            // if (tmpList.size() == 0) {
            //     break;
            // }
            if (cur == 0) {
                break;
            } // 与上面注释的作用一样，但是现在这种直接就会跳出循环，不会再创建一次空的list！
            results.add(tmpList);
        }

        return results;
    }
}
```