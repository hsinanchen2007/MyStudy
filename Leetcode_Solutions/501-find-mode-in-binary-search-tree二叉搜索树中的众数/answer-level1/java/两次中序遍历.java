### 解题思路
中序遍历两次，第一次遍历查找众数出现的最大次数max，第二次遍历时将出现次数为max的数进行记录。

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
    List<Integer> res = new LinkedList<>();
    int max = 0, num = -1, time = 1;

    public void traverse(TreeNode node, int style) {
        if (node == null)
            return;
        traverse(node.left, style);
        if (node.val == num) {
            time++;
        } else {
            num = node.val;
            time = 1;
        }
        if (style == 1) {
            if (time == max)
                res.add(node.val);
        } else {
            max = Math.max(max, time);
        }
        traverse(node.right, style);
    }

    public int[] findMode(TreeNode root) {
        traverse(root, 0);
        num = -1;
        time = 1;
        traverse(root, 1);
        int[] r = new int[res.size()];
        int a = 0;
        for(int i : res){
            r[a] = i;
            a++;
        }
        return r;
    }
}
```