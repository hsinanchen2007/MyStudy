和二叉树的层序遍历的区别在于子节点是一个list
那么把取左右子节点的操作改为遍历子节点的list即可
```
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        //应该是与二叉树的层序遍历一样的.
        //都是通过队列来实现
        //只不过在二叉树里面存孩子是两个TreeNode:left和right
        //在N叉数里面是一个List存着孩子.
        List<List<Integer>> levels = new ArrayList<List<Integer>>();
        if (root == null) return levels;

        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        int level = 0;
         while ( !queue.isEmpty() ) {
             levels.add(new ArrayList<Integer>());

      // number of elements in the current level
      int level_length = queue.size();
      for(int i = 0; i < level_length; ++i) {
            Node node = queue.remove();
            levels.get(level).add(node.val);
            int len=node.children.size();
            if(len!=0){
                for(int j=0;j<len;j++){
                    queue.add(node.children.get(j));
                }
            }       
      }
             level++;             
         }
        return levels;          
         }
    }




```
