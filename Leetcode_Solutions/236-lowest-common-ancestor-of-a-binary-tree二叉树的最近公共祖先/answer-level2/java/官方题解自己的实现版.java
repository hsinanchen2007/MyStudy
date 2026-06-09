### 解题思路
参考官方题解写的代码

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        /**
         * 思路，遍历一遍保存各个节点的父节点
         * 然后找出p对应的父节点集合
         * 则q节点对应的公共父节点肯定也在这个集合中
         * 找到返回即可
         *
        */
        //bad-case
        if (root == null || root == p || root == q) {
            return root;
        }

        //栈保存遍历内容
        Deque<TreeNode> stack = new ArrayDeque();

        //hash表保存各个节点的父节点
        Map<TreeNode, TreeNode> map = new HashMap();

        //栈节点
        stack.addFirst(root);

        //保存父子节点
        map.put(root, null);

        //如果找到了p or q节点 循环结束
        while (!map.containsKey(p) || !map.containsKey(q)) {
            //出栈
            TreeNode node = stack.removeFirst();

            //右节点
            if (node.right != null) {
                stack.addFirst(node.right);
                map.put(node.right, node);
            }

            //左节点
            if (node.left != null) {
                stack.addFirst(node.left);
                map.put(node.left, node);
            }
        }

        //使用集合保存p的父子集合
        Set<TreeNode> set = new HashSet();
        while (p != null) {
              set.add(p); 
              p = map.get(p);
        }
        

        //找出q
        while (q != null) {
            if (set.contains(q)) {
                return q;
            }
            q = map.get(q);
        }

        return null;
    }
}
```