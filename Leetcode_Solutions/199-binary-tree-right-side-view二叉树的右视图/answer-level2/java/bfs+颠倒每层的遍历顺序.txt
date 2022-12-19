### 解题思路
这道题目实质上是树的层次遍历变形，树的层次遍历当然使用bfs。需要注意的两个点：
- bfs中树的每层节点数为当前队列的大小
- 由于是从右向左看的，我们按照`右孩子、左孩子`的顺序入队，这样每次队首就是最右边的孩子，加入`ans list`便可
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer>  ans = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if(root == null) return ans;
        queue.add(root);
        while(!queue.isEmpty()) {
            int n = queue.size();
            ans.add(queue.peek().val);
            for(int i = 0; i < n; i++) {
                TreeNode node = queue.poll();
                if(node.right != null) queue.add(node.right);
                if(node.left != null) queue.add(node.left);
            }
        }
        return ans;
    }
}
```