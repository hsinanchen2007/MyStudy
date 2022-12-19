def isSameTree(p: TreeNode, q: TreeNode): Boolean = {
    if(p==null && q==null) return true
    if(p!=null && q!=null){
      if(p.value==q.value){
        if(isSameTree(p.left,q.left) && isSameTree(p.right,q.right)) return true
      }
    }
    false
  }