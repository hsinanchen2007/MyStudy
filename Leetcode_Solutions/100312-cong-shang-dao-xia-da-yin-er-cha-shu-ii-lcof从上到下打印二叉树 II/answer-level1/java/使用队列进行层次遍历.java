### 解题思路
此处撰写解题思路
使用队列进行层次遍历，即从左到右，先进先出；还需要记录下每一层节点的个数
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> lists = new ArrayList<>();
        if(root == null)
            return lists;
        Queue<TreeNode> queue = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        queue.add(root);
        int pre = 1, cur = 0;
        while(!queue.isEmpty()){
            TreeNode node = queue.poll();
            list.add(node.val);
            pre--;
            if(node.left != null){
                queue.add(node.left);
                cur++;
            }
            if(node.right != null){
                queue.add(node.right);
                cur++;
            }
            if(pre == 0){
                lists.add(new ArrayList<>(list));
                list.clear();
                pre = cur;
                cur = 0;
            }
        }
        return lists;
    }
}
```