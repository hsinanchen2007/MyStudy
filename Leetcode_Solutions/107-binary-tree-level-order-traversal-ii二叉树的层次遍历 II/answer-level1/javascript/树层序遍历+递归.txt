## 树层序遍历实现

```js
var levelOrderBottom = function(root) {
  if(!root)return [];
  let queue=[root];
  let res=[];
  let level=0;
  while(queue.length){
    let temp=[];
    res[level]=[];
    for(let i=0;i<queue.length;i++){
      res[level].push(queue[i].val);
      if(queue[i].left){
        temp.push(queue[i].left);
      }
      if(queue[i].right){
        temp.push(queue[i].right);
      }
    }
    queue=temp;
    ++level;
  }
  return res.reverse();
};
```

## 递归实现

```js
var levelOrderBottom = function(root) {
  let res=[];
  const deepf=(node,level)=>{
    if(!node){
      return
    }
    res[level]?res[level].push(node.val):res[level]=[node.val];
    level++;
    deepf(node.left,level);
    deepf(node.right,level);
  }
  deepf(root,0)
  return res.reverse();
};
```