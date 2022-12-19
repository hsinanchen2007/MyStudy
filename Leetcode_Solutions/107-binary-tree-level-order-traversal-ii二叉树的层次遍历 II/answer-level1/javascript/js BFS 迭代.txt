![image.png](https://pic.leetcode-cn.com/883e33ad918ccc0925c21fcaa329cf3c2b3e6eaf70f6af1ff743474190de5bc7-image.png)

### 解题思路
```js
@yueshuiniao 学到了巧妙的计数方式
优化计数方式
```

### 代码
```js

var levelOrderBottom = function(root) {
  let queue = [],
      ans = [],
      temp = [];
  
  if (root) queue.push(root);
  
  while (queue.length > 0) {
    let count = queue.length;
    
    while (count > 0) {
      let curr = queue.shift();
      if (curr) {
        temp.push( curr.val );
        if (curr.left) queue.push( curr.left );
        if (curr.right) queue.push( curr.right );
      }
      count--;
    }
    
    ans.unshift( [...temp] );
    temp = [];
  }
  
  if (temp.length !== 0) ans.unshift( [...temp] );
  
  return ans;
};

/*
  BFS + 正向逐层遍历，往头上 unshift
*/
// var levelOrderBottom = function(root) {
//   let queue = [],
//       ans = [],
//       count = 1,
//       nextCount = 0,
//       time = 0,
//       temp = [];
  
//   queue.push(root);
  
//   while (queue.length > 0) {
//     if (time === count && count !== 0) {
//       ans.unshift( [...temp] );
//       temp = []; count = nextCount; nextCount = 0; time = 0;
//     }
    
//     let curr = queue.shift();
//     if (curr) {
//       time++;
//       temp.push( curr.val );
      
//       if (curr.left) {
//         queue.push( curr.left );
//         nextCount++;
//       }
//       if (curr.right) {
//         queue.push( curr.right );
//         nextCount++;
//       }
//     }
//   }
  
//   if (temp.length !== 0) ans.unshift( [...temp] );
  
//   return ans;
// };
```