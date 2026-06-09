### 解题思路
这题由两步组成：
1. 获取树的深度d，这样就可以确认list的长度为2^d - 1
2. 生成每一层的树的list，使用步长来处理，每个节点的pos=step * j + step / 2 - 1;
![image.png](https://pic.leetcode-cn.com/66c0d2ffbc0c9ee2698d1dd059770955d17f98a01b51dbc80657e5429b423cd5-image.png)


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
    public List<List<String>> printTree(TreeNode root) {
        int depth = getDepth(root, 0);
        int length = (1 << depth) - 1;

        List<List<String>> result = new ArrayList<>();
        List<TreeNode> nodes = new ArrayList<>();
        nodes.add(root);
        TreeNode nullChildNode = new TreeNode(0);
        int step = length + 1;
        for (int i = 0; i < depth; i++) {
            List<String> item = new ArrayList<>(length);
            for (int j = 0; j < length; j++) {
                item.add("");
            }
            List<TreeNode> next = new ArrayList<>();
            for (int j = 0; j < nodes.size(); j++) {
                TreeNode node = nodes.get(j);
                if (node != null) {
                    int pos = j * step + step / 2 - 1;
                    item.set(pos, Integer.toString(node.val));
                } else {
                    node = nullChildNode;
                }
                next.add(node.left);
                next.add(node.right);
            }

            result.add(item);
            step = ((step - 1) >> 1) + 1;
            nodes = next;
        }

        return result;
    }

    private int getDepth(TreeNode node, int depth) {
        if (node == null) return depth;
        int right = getDepth(node.left, depth + 1);
        int left = getDepth(node.right, depth + 1);
        return Math.max(left, right);
    }
}
```