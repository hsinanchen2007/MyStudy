```
object Solution {
    def hasPathSum(root: TreeNode, sum: Int): Boolean = {
      if (root == null) return false
      if (root.left == null && root.right == null && root.value == sum ) return true
      return hasPathSum(root.left, sum - root.value) || hasPathSum(root.right, sum - root.value)
    }
    //def hasPathSum(root: TreeNode, sum: Int): Boolean = {
      //if (root == null) return false
      //import scala.collection.mutable.Stack
      //val mystack = new Stack[(TreeNode,Int)]()
      //mystack.push((root,root.value))

      //while(mystack.nonEmpty){
        //val (node, acc) = mystack.pop
        //if( node.left == null && node.right == null && acc == sum) {
          //return true
        //}
        //if(node.left!=null){
          //mystack.push((node.left, acc+node.left.value))
        //}
        //if(node.right!=null){
          //mystack.push((node.right, acc+node.right.value))
        //}
      //}
      //return false
    //}
}
//leetcode submit region end(Prohibit modification and deletion)

```
