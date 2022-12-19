
```
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}
// 递归解题
var mergeTrees = function(t1, t2) {
   if(!t1 && t2) return t1 = t2
   if(!t1 && !t2) return null
   if(t1 && t2) t1.val += t2.val
   t1.left = mergeTrees(t1.left, t2 && t2.left)
   t1.right = mergeTrees(t1.right, t2 && t2.right)
   return t1
};

//迭代解题
var mergeTrees = function(t1, t2) {
  if(!t1 || !t2) return t1 || t2
  const res = [[t1, t2]]
  while(res.length) {
    const t = res.pop()
    t[0].val += t[1].val
    if(t[0].left && t[1].left) {
      res.push([t[0].left, t[1].left])
    }
    if(t[0].right && t[1].right) {
      res.push([t[0].right, t[1].right])
    }
    if(!t[0].left && t[1].left) {
      t[0].left = t[1].left
    }
    if(!t[0].right && t[1].right) {
      t[0].right = t[1].right
    }
  }
  return t1
};
```

