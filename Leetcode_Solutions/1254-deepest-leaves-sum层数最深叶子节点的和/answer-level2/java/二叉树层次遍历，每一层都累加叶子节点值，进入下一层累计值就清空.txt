### 解题思路
这题其实蛮简单的，比较基础。
二叉树层次遍历，每一层都累加叶子节点值，进入下一层累计值就清空sum值，不知道有没有大神指导怎么样可以不每层都累加吗？如果是先求高度在广度遍历，我觉得就没必要了，循环两次的时间肯定比一次循环中多一个累加操作要多。

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
    public int deepestLeavesSum(TreeNode root) {
        if (root == null){
            return 0;
        }
        TreeNode node = root;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(node);
        int front = 0;
        int rear = queue.size();
        int sum = 0;
        while (true){
            node = queue.poll();
            front++;
            if (node.left == null && node.right == null){
                sum += node.val;// 叶子节点值累加
            }else {
                if (node.left != null){
                    queue.offer(node.left);
                }
                if (node.right != null){
                    queue.offer(node.right);
                }
            }
            if (queue.isEmpty()){
                break;// 队列空表示所有节点都遍历结束
            }
            // 队列还有元素，进入下一层，本层累计值清0
            if (front == rear){
                front = 0;
                rear = queue.size();
                sum = 0;
            }
        }
        return sum;
    }
}
```