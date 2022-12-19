基于二叉树层序遍历改一点代码即可.
本题和普通的层序遍历区别在于如何正确的选取加入子节点的顺序以及先后.
根据题目样例.我们需要先在levels中加入3,然后是20,9.然后是9下方的子节点(如果有的话,然后是20底下的子节点)
所以队列肯定完成不了这个任务(必须先加入先出,而20的子节点先于9的子节点加入,遍历时却要求9的子节点在前)
所以我使用stack
而单一stack会存在前一层的元素还未pop干净的时候,下一层子节点就已经开始加入的问题
所以使用双stack,偶数层一个,奇数层一个.互不打扰.且奇偶层加入左右节点的顺序相反.

```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
   List<List<Integer>> levels = new ArrayList<List<Integer>>();
    if (root == null) return levels;
    Stack<TreeNode> stack_odd = new Stack<TreeNode>();
    Stack<TreeNode> stack_even = new Stack<TreeNode>();
    stack_even.push(root);
    int level = 0;
    while ( !stack_odd.isEmpty()||!stack_even.isEmpty() ) {
      // start the current level
      levels.add(new ArrayList<Integer>());
     if(level%2==0){
      int level_length = stack_even.size();
      for(int i = 0; i < level_length; ++i) {
        TreeNode node = stack_even.pop();
        levels.get(level).add(node.val);
        if (node.left != null) stack_odd.push(node.left);
        if (node.right != null) stack_odd.push(node.right);
      }      
     }
    else{
        int level_length = stack_odd.size();
      for(int i = 0; i < level_length; ++i) {
        TreeNode node = stack_odd.pop();
        levels.get(level).add(node.val);
        if (node.right != null) stack_even.push(node.right);
        if (node.left != null) stack_even.push(node.left);          
    }        
    }
         level++;    
  }
return levels;
    }}

     
```
