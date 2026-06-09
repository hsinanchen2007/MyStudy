### 解题思路
使用两个队列，第一个队列用来存储上一层的结果，然后弹出队列中的值，再一次循环，把上一层的下一层节点存储到临时
队列里，当本层节点循环遍历完成之后，把临时队列赋值给第一个队列，然后继续循环即可。

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
        List<Double> list=new ArrayList<Double>();
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            long sum=0;long count=0;
            Queue<TreeNode>temp=new LinkedList<TreeNode>();
            while(!queue.isEmpty()){
                TreeNode node=queue.poll();
                sum+=node.val;
                count++;
                if(node.left!=null) temp.add(node.left);
                if(node.right!=null) temp.add(node.right);
            }
            queue=temp;
            list.add(sum*1.0/count);
        }
        return list;
    }
}
```