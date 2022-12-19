### 解题思路 利用一个双端队列，存每一层的结点。
另一种方法，求其大小值，全弹出之后，，队列中剩余的大小即为下一层中的值的多少。


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
       List<Double> list=new ArrayList<>();
       if(root==null) return list;
       Deque<TreeNode> queue=new LinkedList<>();
       queue.add(root);
       TreeNode temp=null,lastNode=root;
       double count=0,sum=0;
       while(!queue.isEmpty()){
            temp=queue.poll();
            count++;
            
            if(temp.left!=null) queue.add(temp.left);
            if(temp.right!=null) queue.add(temp.right);
            sum+=temp.val;
            if(temp==lastNode){
                lastNode=queue.peekLast();
                list.add(sum/count);
                sum=0;
                count=0;

            }
           

       } 
       return list;
    }
}
```