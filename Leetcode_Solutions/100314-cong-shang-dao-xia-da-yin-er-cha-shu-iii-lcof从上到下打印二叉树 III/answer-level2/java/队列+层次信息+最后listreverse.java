### 解题思路
1.使用队列和层次信息 存储List<List<Integer>> 每一层的层次遍历结果
2.对单数层进行reverse操作

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
    static class LevelNode{
        TreeNode node;
        int level;

        public LevelNode(TreeNode node, int level) {
            this.node = node;
            this.level = level;
        }
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        LinkedList<LevelNode> queue = new LinkedList<LevelNode>();
        if (root == null) return res;
        queue.offer(new LevelNode(root, 0));
        while (!queue.isEmpty()) {
            LevelNode cur = queue.poll();
            if (res.size()==cur.level) {
                List<Integer> curlevel = new ArrayList<>();
                res.add(curlevel);
            }
            res.get(res.size()-1).add(cur.node.val);

            if (cur.node.left!=null)
                queue.add(new LevelNode(cur.node.left, cur.level+1));
            if (cur.node.right!=null)
                queue.add(new LevelNode(cur.node.right, cur.level+1));

        }
        for (int i=0;i<res.size();i++) {
            if ((i&1)==1) {
                Collections.reverse(res.get(i));
            }
        }
        return res;
    }

}
```
![image.png](https://pic.leetcode-cn.com/7b648d93bae8e2de93795a2af122c0f8e1bad994043209d86be5ccff0c1a5f98-image.png)
