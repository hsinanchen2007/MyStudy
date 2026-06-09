思路嘛， 和大家的一样， 层次遍历， 保存最大层数据就行了。
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
    public int maxLevelSum(TreeNode root) {
        int res = 0;
        if (root == null) {
            return res;
        }
        int[] maxLevel = {Integer.MIN_VALUE, 0};
        List<TreeNode> list = new ArrayList<>();
        list.add(root);
        int startLevel = 1;
        while (list.size() != 0) {
            List<TreeNode> temp = new ArrayList<>();
            int tempNum = 0;
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i).left != null) {
                    temp.add(list.get(i).left);
                }
                if (list.get(i).right != null) {
                    temp.add(list.get(i).right);
                }
                tempNum += list.get(i).val;
            }
            if (tempNum > maxLevel[0]) {
                maxLevel[0] = tempNum;
                maxLevel[1] = startLevel;
            }
            startLevel++;
            list = temp;
        }
        return maxLevel[1];
    }
}
```