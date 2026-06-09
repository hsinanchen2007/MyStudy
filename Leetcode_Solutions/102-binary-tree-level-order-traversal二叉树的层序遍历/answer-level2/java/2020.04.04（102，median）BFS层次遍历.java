### 解题思路
本题要求层次遍历每层结点并放入一个二维数组中

- 首先就创建一个**二维数组**用来接收最后的结果，同时做**判空**操作

- 接下来就是层次遍历用到的典型的**队列**，队列中每次只存放**一层的结点**，然后创建一个**一维数组**用来接收队列中**每次存放的元素**

- 然后如果有左右孩子就将他们也**入队再放入数组**中，然后一维数组再放入二维数组中

- 等到遍历完所有的结点，返回 `ans` 即可。

### 代码

```java []
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
        // 创建二维数组接收每层的结点
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        // 创建队列依次存放每层的结点
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            // 创建数组来接收出队的结点，存放的是每层的结点
            List<Integer> tmp = new ArrayList<>();
            int len = q.size();
            for (int i = 0; i < len; i++) {
                // 定义 node 接收出队结点，然后加入数组 tmp 中
                TreeNode node = q.poll();
                tmp.add(node.val);
                // 如果有左右孩子，就依次入队、出队、进数组
                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add(node.right);
                }
            }
            // 数组每次都是放的一层的结点，然后一层一层的放入二维数组中
            ans.add(tmp);
        }
        return ans;
    }
}

```