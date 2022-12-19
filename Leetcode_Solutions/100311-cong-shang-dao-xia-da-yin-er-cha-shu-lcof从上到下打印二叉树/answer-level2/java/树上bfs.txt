### 解题思路
此处撰写解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
98.76%
的用户
内存消耗 :
39.4 MB
, 在所有 Java 提交中击败了
100.00%
的用户
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
    public int[] levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<Integer> tmp = new ArrayList<>();
        int[] res = new int[0];
        if (root == null) return res;
        queue.add(root);
        while (!queue.isEmpty()){
            int size = queue.size();
            for (int i = 0; i < size; i++){
                TreeNode node = queue.poll();
                tmp.add(node.val);
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        int cnt[] = new int[tmp.size()];
        for (int i = 0; i < tmp.size(); i++){
            cnt[i] = tmp.get(i);
        }
        return cnt;
    }   
}
```