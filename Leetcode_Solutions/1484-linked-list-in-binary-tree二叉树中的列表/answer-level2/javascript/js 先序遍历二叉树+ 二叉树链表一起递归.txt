先序遍历二叉树，寻找 `root.val == head.val` 的二叉树节点，与链表开头不一样的直接略过

每次找到这种节点后，递归的判断该子树能否和链表匹配上，见代码中的help()函数

```js
var isSubPath = function(head, root) {
  if(root === null){
    return false;
  }
  //找到值等于链表头的二叉树节点，尝试连续的判断二叉树和链表是否对应
  if(head.val === root.val){
    let tmp = help(head,root);
    if(tmp){
      return true;
    }
  }
  //先序遍历二叉树
  return  isSubPath(head,root.left) ||   isSubPath(head,root.right);
};

//连续的判断二叉树和链表是否对应
function help(head,root){
  if(head === null) return true;//遍历完链表
  if(root === null) return false;
  
  if(head.val === root.val){
    return help(head.next, root.left) || help(head.next, root.right);
  }else{
    return false;
  }
}
```
