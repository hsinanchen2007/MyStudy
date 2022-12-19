### 解题思路
看了官方，自己独立实现一遍，但是发现结果怎么都不对，遂调试半天，发现我定义的int，超出限制了 -_-#。

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
    
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            long sum = 0,count = 0;
            Queue<TreeNode> temp = new LinkedList<TreeNode>();
            while(!queue.isEmpty()){
                TreeNode n = queue.remove();
                sum += n.val;
                count++;
                if(n.left != null){
                    temp.add(n.left);
                }
                if(n.right != null){
                    temp.add(n.right);
                }
            }
            queue = temp;
            result.add(sum * 1.0/count);
        }
        return result;
    }
}
```