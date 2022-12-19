### 解题思路
实际上就是二叉树的层序遍历，利用队列queue进行求解。由于只需要求得层平均值，所以只需要一个sum存储层的和。

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
        List<Double> res = new ArrayList<>();
        if(root == null) return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        //res.add(root.val);
        int cur = 0,count = 1;
        double sum = 0;
        while(!queue.isEmpty()){
            TreeNode temp = queue.poll();
            sum += temp.val;
            if(temp.left != null){
                queue.offer(temp.left);
            }
            if(temp.right != null){
                queue.offer(temp.right);
            }
            cur ++;
            if(cur == count){
                res.add(sum/count);
                count = queue.size();
                cur = 0;
                sum = 0;
            }
            
        }
        return res;
    }
}
```