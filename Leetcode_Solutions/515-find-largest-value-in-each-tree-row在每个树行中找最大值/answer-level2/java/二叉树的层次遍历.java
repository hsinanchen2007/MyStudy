### 解题思路
这一题其实还是在考察二叉树的层次遍历。比较每一轮队列中那个元素值最大即可。

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
    public List<Integer> largestValues(TreeNode root) {
        //传统的二叉树层次遍历没有第二个while循环。
        //这个队列中每一次经过外层循环的时候，队列中的元素都是同一层的元素。
        //然后将队列的第一个元素赋值给ans就可以了。

        if(root == null)
            return new ArrayList<>();

        int max;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<TreeNode> list = new ArrayList<TreeNode>();
        List<Integer> res = new ArrayList<Integer>();
        queue.offer(root);

        while(!queue.isEmpty()){
            max = Integer.MIN_VALUE;
            while(!queue.isEmpty()){
                list.add(queue.poll());
            }
            while(list.size() != 0){
                TreeNode node = list.get(0);
                max = max > node.val ? max : node.val;
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
                list.remove(0);
            }
            res.add(max);
        }
        return res;
    }
}
```