```
var levelOrder = function(root) {
  if(!root) return []
   let res=[];
   let queue=[root];
   let j=0
   while(queue.length){
     res[j]=[];
     let length=queue.length;
     for(let i=0;i<length;i++){
       let node=queue.shift();
       res[j].push(node.val);
       if(node.left) queue.push(node.left);
       if(node.right) queue.push(node.right);
     }
     j++;
   }
   return res 
};
```
