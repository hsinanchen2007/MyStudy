### 解题思路
此处撰写解题思路
follow up应该也不难，再加一个同样的bfs在origin上面，比较的时候不能拿.val比较
不origin的话就不能用 == 因为引用不在一起，equals也不能，因为有多个相同val值的node
执行用时 :
6 ms
, 在所有 Java 提交中击败了
16.46%
的用户
内存消耗 :
46.9 MB
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
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if (cloned == null) return null;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(cloned);
        TreeNode tmp = null;
        while (!queue.isEmpty()){
            int size = queue.size();
            for (int i = 0; i < size; i++){
                tmp = queue.poll();
                if (tmp.val == target.val) return tmp;
                if (tmp.left != null) queue.offer(tmp.left);
                if (tmp.right != null) queue.offer(tmp.right);
            }
        }
        return null; 
    }
}
```