### 解题思路
二叉树层次遍历 使用队列
此题的重点是 如果确定队列正在遍历的是那一层
我采用的是最笨的方式 使用两个变量分别保存当前层的数量和次级层的数量

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.ArrayList;
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
        //二叉树的层次遍历 + 使用队列解法
        Queue<TreeNode> queue = new LinkedList<TreeNode>();

        //返回的列表
        List<List<Integer>> list = new ArrayList<>();

        //空二叉树
        if (root == null) {
            return list;
        }

        //入队列
        queue.offer(root);

        //第一层数量
        int fLevelCount = 1;

        //第二层数量
        int sLevelCount = 0;

        //层数
        List<Integer> listItem = new ArrayList<>();

        //队列非空
        while (!queue.isEmpty()) {
        
            //层数量 -1
            fLevelCount --;
            
            TreeNode node = queue.poll();
            listItem.add(node.val);


            //左节点入队列
            if (node.left != null) {
                sLevelCount++;
                queue.offer(node.left);
            }

            //右节点入队列
            if (node.right != null) {
                sLevelCount++;
                queue.offer(node.right);
            }

                //当前层遍历到了
            if (fLevelCount == 0) {
                list.add(listItem);
                //重新赋值
                listItem = new ArrayList<>();
                fLevelCount = sLevelCount;
                sLevelCount = 0;
            }
        }

        return list;
    }
}
```