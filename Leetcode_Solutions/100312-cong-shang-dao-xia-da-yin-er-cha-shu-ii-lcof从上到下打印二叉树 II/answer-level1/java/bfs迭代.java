### 解题思路
在1的基础上增加来一个变量level表示层，for循环遍历每层的数据
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
    private List<List<Integer>> list=new ArrayList<List<Integer>>();
    
    public List<List<Integer>> levelOrder(TreeNode root) {
   if(root==null) return list;
    Deque<TreeNode> deque = new LinkedList<>();
    deque.add(root);
    int level =0;

    while(!deque.isEmpty()){
      list.add(new ArrayList<Integer>());
      int length =deque.size();
      for(int i=0;i<length;i++){
        TreeNode tree =  deque.remove();
          list.get(level).add(tree.val);

         TreeNode left = tree.left;
         TreeNode right = tree.right;
         if(left!=null) deque.add(left);
         if(right!=null) deque.add(right);
      }
               level++;

    }
return list;



    }
}
```