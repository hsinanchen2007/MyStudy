### 解题思路
此处撰写解题思路
    将二叉树做广度优先遍历，讲节点存入队列，并记录当前层级节点数,利用队列先进先出特性,每次弹出当前层级数量节点,并将下一层级节点放入
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
    List<List<Integer>> list = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null){
            return list;
        }
        levelListOrderGuan(root);
        return list;
    }

    /**
     * 二叉树广度遍历
     */
    public void levelListOrderGuan(TreeNode root){
        // 创建队列
        LinkedList<TreeNode> queue = new LinkedList<>();
        // 将根节点加入
        queue.add(root);
        // 队列不为 null 一直遍历
        while (!queue.isEmpty()){
            // 创建集合 存储当前深度所有节点
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode node = queue.pop();
                // 当前节点放入集合
                tmp.add(node.val);
                // 当前节点子节点放入队列
                if (node.left != null){
                    queue.add(node.left);
                }
                if (node.right != null){
                    queue.add(node.right);
                }
            }
            list.add(tmp);
        }
    }
}
```