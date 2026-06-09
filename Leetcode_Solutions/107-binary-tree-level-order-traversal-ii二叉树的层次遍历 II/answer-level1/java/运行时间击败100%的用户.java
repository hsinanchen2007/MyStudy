### 解题思路
此处撰写解题思路
使用1个队列来保存需要遍历的节点，有一个问题需要解决：如何分层？我的做法是设置一个哨兵节点null，每次从队列里取节点，
如果遇到null，说明当前层已经遍历完，即将进入下一层，所以可以将这一层的所有节点组成的list添加到结果队列的头部，
并且要在节点队列的末尾新增一个null哨兵。
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null)
            return new ArrayList<>();
        List<List<Integer>> result = new LinkedList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.addLast(null);
        LinkedList<Integer> tempList = null;
        while(!queue.isEmpty()){
            TreeNode node = queue.removeFirst();
            if(node == null){
                if(tempList != null){
                    ((LinkedList<List<Integer>>) result).addFirst(tempList);
                    tempList = null;
                    queue.addLast(null);
                    continue;
                }
            } else {
                if(tempList == null){
                    tempList = new LinkedList<>();
                }
                tempList.addLast(node.val);
                if(node.left != null){
                    queue.addLast(node.left);
                }
                if(node.right != null){
                    queue.addLast(node.right);
                }
            }

        }
        return result;
    }
}
```