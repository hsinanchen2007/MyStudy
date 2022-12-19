### 解题思路
1.谈到计数，想到map，利用中序遍历，将所有节点值存入map。
2.遍历map，拿到最大的value 即保存在max遍历。
3.再次遍历map，拿到所有value值等于max的key。
4.返回结果。

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
    Map<Integer, Integer> map = new HashMap<>();

    public int[] findMode(TreeNode root) {
        mid(root);
        int max = -1;
        for (Map.Entry entry : map.entrySet()) {
            max = Math.max((int) entry.getValue(), max);
        }

        List<Integer> result = new ArrayList<>();
        for (Map.Entry entry : map.entrySet()) {
            if ((int) entry.getValue() == max) {
                result.add((int) entry.getKey());
            }
        }
        int[] results = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            results[i] = result.get(i);
        }
        return results;
    }

    private void mid(TreeNode root) {
        if (root == null) {
            return;
        }
        mid(root.left);
        map.put(root.val, map.getOrDefault(root.val, 0) + 1);
        mid(root.right);
    }
}
```