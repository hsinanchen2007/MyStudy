### 解题思路
利用Java8 Stream优雅解决

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
import java.util.*;
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        List<TreeNode> l = new ArrayList<>();
        l.add(root);
        while(!l.isEmpty()) {
            res.add(l.stream().map(n -> n.val).collect(Collectors.toList()));
            l = l.stream()
                .flatMap(n -> Stream.of(n.left, n.right))
                .filter(Objects::nonNull)
                .collect(Collectors.toList());
        }
        return res;
    }
}
```