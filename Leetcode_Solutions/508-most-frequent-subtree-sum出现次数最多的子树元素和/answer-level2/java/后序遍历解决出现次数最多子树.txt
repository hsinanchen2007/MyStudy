### 解题思路
后序遍历树，从下往上计算子树值，然后计算出现次数最多的子树

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
    Map<Integer, Integer> map;
    int maxCount;
    int num;
    public int[] findFrequentTreeSum(TreeNode root) {
        map = new HashMap<>();
        int[] result = null;
        if (root == null) {
            return new int[0];
        }
        maxCount = 0;
        num = 0;
        int rootNum = dfs(root);
        result = new int[num];
        for (Map.Entry<Integer, Integer> entry:map.entrySet()) {
            if (entry.getValue().intValue() == maxCount) {
                result[--num] = entry.getKey();
            }
        }
        return result;
    }
    public int dfs(TreeNode node) {
        int leftNum = 0;
        int rightNum = 0;
        if (node.left != null) {
            leftNum = dfs(node.left);
        }
        if (node.right != null) {
            rightNum = dfs(node.right);
        }
        int finalNum = leftNum + rightNum + node.val;
        //System.out.println(finalNum);
        // 设置map
        int countNumber = 0;
        if (map.get(finalNum) == null) {
            map.put(finalNum, 1);
            countNumber = 1;
        } else {
            Integer v = map.get(finalNum);
            map.put(finalNum, v+1);
            countNumber = v+1;
        }
        System.out.println(countNumber);
        if (countNumber > maxCount) {
            maxCount = countNumber;
            num = 1;
        } else if (countNumber == maxCount) {
            num++;
        }
        return finalNum;
    }
}
```