### 解题思路
此处撰写解题思路
递归遍历数建立每一层自己的list

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
  private Map<Integer, List<Integer>> map = new HashMap<>();

    public int findBottomLeftValue(TreeNode root) {

        find(root, 0);

        List<Map.Entry<Integer, List<Integer>>> collect =
                map.entrySet().stream().sorted((l,r)->{return Integer.compare(r.getKey(),l.getKey());}).collect(Collectors.toList());


        return collect.get(0).getValue().get(0);
    }

    private void find(TreeNode treeNode, int lv) {
        if (null == treeNode) {
            return;
        }
        map.computeIfAbsent(lv, (t) -> {
            ArrayList<Integer> integers = new ArrayList<>();
            integers.add(treeNode.val);
            return integers;

        });
        map.compute(lv, (key, ov) -> {
            if (null == ov) {
                ov = new ArrayList<>();

            }
            ov.add(treeNode.val);
            return ov;
        });
        find(treeNode.left, lv + 1);
        find(treeNode.right, lv + 1);

    }
}
```