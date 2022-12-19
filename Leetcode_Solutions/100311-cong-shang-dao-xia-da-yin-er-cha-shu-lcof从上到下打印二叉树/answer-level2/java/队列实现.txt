### 解题思路
根据队列“先进先出”的原则，可以不断将每层的结点加入到队列中，之后不断取出并添加到数组中
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
    public int[] levelOrder(TreeNode root) {
        if(root==null){
            return new int[0];
        }
     Deque<TreeNode> deque= new LinkedList<>();
   ArrayList<Integer>  list =new ArrayList<>();
      deque.offer(root);
     while(!deque.isEmpty()){
         int size =deque.size();
         TreeNode tree =  deque.poll();
        list.add(tree.val);
        TreeNode left =tree.left;
        TreeNode right= tree.right;
        if(left!=null){
        deque.offer(left);
        }
        if(right!=null){
        deque.offer(right);
        }     
     }
     int[] arr  =new int[list.size()];
     int index=0;
     for(Integer data:list){
         arr[index++]=data;
     }
      return arr;
    }
}
```