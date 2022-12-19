//若当前节点非空，则将该节点val值放在path中
若此时为叶子结点，则将该path放进paths中
若此时不是叶子节点，则递归当前每一个的孩子结点

var binaryTreePaths = function(root) {
      //let paths=[]
      return construct_paths(root)
};

function construct_paths(root,path = "",paths=[]){
  if(root!==null){ //节点非空
    path += root.val
    if((root.left===null)&&(root.right===null)){ //为叶子结点   
      paths.push(path)
    }else{
      path+=`->`
      construct_paths(root.left,path,paths)
      construct_paths(root.right,path,paths)
    }
  }
 return paths
}