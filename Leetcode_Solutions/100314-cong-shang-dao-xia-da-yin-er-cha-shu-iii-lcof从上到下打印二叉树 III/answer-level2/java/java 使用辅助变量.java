### 解题思路
设置辅助变量theLayerNumber，表示当前的层数
在添加时进行判断，如果是偶数则先反转链表再添加。

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
   //方法一，正常输出，最后将奇数层的list反转
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new LinkedList<>();
        List<List<Integer>> result = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int theLayerNumber = 1;    //标记层数是奇数还是偶数
        while (!queue.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            Queue<TreeNode> assist = new LinkedList<>(); //辅助链表，暂时存放下一层的结点
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                if (node.left != null) assist.add(node.left);
                if (node.right != null) assist.add(node.right);
                list.add(node.val);
            }
            queue = assist;
            if (theLayerNumber++ % 2 == 0) {
                Collections.reverse(list);
            }
            result.add(list);
        }
        return result;
    }
}
```