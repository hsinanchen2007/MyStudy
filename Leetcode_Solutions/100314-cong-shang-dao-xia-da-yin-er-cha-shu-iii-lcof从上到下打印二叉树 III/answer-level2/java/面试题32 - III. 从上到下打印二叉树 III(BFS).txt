### 解题思路
在上一题基础上，当输出时候判断层数，偶数层需要翻转，奇数层不用，使用reverse函数即可

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
        List<List<Integer>> res=new ArrayList<>();
        if(root!=null)queue.add(root);
        while(!queue.isEmpty()){
            List<Integer> tmp=new ArrayList<>();//用来存每一层的节点值
            int num=queue.size();//用来存队列的元素个数的，个数代表这一层有几个节点
            for(int i=num;i>0;i--){//这层有几个节点就循环几次，每次循环代表判断一个节点是否有左右子树
                TreeNode node=queue.poll();
                tmp.add(node.val);
                if(node.left!=null)queue.add(node.left);
                if(node.right!=null)queue.add(node.right);
            }
            if(res.size()%2==1)Collections.reverse(tmp);
            res.add(tmp);
        }
        return res;
    }
}
```