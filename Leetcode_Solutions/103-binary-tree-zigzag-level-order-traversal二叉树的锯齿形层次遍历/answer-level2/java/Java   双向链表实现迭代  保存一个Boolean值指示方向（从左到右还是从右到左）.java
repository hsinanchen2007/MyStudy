### 解题思路
详见注释

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> lists = new ArrayList<>();
        if (root == null) {
            return lists;
        }
        boolean forward = true; //从左到右为true，从右到左为false
        LinkedList<TreeNode> linkedList = new LinkedList<>();   //双向链表保存节点
        linkedList.add(root);
        while (!linkedList.isEmpty()) {
            int size = linkedList.size();
            List<Integer> list = new ArrayList<>(size); //记录上层的数据
            for (int i = 0; i < size; i++) {    //遍历上一层的全部节点（可能有null）
                TreeNode treeNode = linkedList.pollLast();  //头部保存，尾部弹出（先进先出）
                if (treeNode == null) { //如果节点是null，直接跳过
                    continue;
                }
                list.add(treeNode.val); //保存上层节点的数据
                linkedList.addFirst(forward ? treeNode.left  : treeNode.right); //如果方向是从左到右，先保存左节点，再保存右节点
                linkedList.addFirst(forward ? treeNode.right : treeNode.left);  //如果方向是从右到左，先保存右节点，再保存左节点
            }
            if (!list.isEmpty()) {
                lists.add(list);
            }
            forward = !forward; //转向
            Collections.reverse(linkedList);    //双向链表一定要反转
        }
        return lists;
    }
}
```