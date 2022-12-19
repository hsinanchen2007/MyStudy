object MergeTrees {
    def main(args: Array[String]): Unit = {
        val node1 = new TreeNode(1)
        node1.left=new TreeNode(3)
        node1.right=new TreeNode(2)
        node1.left.left=new TreeNode(5)

        val node2 = new TreeNode(2)
        node2.left=new TreeNode(1)
        node2.right=new TreeNode(3)
        node2.left.right=new TreeNode(4)
        node2.right.right=new TreeNode(7)

        val node: TreeNode = merge(node1,node2)

        println(node._value)
        println(node.left._value)
        println(node.right._value)
        println(node.left.left._value)
        println(node.left.right._value)
        println(node.right.right._value)

    }

    def merge(t1: TreeNode, t2: TreeNode): TreeNode ={
        var result:TreeNode=null
        if(t1!=null && t2!=null){
            result=new TreeNode(t1.value+t2.value)
            if(t1.left!=null && t2.left!=null ){
                result.left=merge(t1.left,t2.left)
            }
            if(t1.right!=null && t2.right!=null ){
                result.right=merge(t1.right,t2.right)
            }
            if(t1.left!=null && t2.left==null ){
                result.left=t1.left
            }
            if(t1.left==null && t2.left!=null ){
                result.left=t2.left
            }
            if(t1.right!=null && t2.right==null ){
                result.right=t1.right
            }
            if(t1.right==null && t2.right!=null ){
                result.right=t2.right
            }

        }
        if(t1==null && t2==null){
            result=null
        }
        if(t1!=null && t2==null){
            result=new TreeNode(t1.value)
            if(t1.left!=null){
                result.left=t1.left
            }
            if(t1.right!=null){
                result.right=t1.right
            }
        }
        if(t1==null && t2!=null){
            result=new TreeNode(t2.value)
            if(t2.left!=null){
                result.left=t1.left
            }
            if(t2.right!=null){
                result.right=t1.right
            }
        }

        result
    }

}

class TreeNode(var _value: Int) {
      var value: Int = _value
      var left: TreeNode = null
      var right: TreeNode = null
}