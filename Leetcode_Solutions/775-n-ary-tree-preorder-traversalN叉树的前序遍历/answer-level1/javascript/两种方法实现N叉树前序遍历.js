方法一： 递归

```javascript
/**
 * 递归算法
 * @param {Node} root
 * @return {number[]}
 */
var preorder = function(root) {
  if(!root) return [];
  return Array.prototype.concat.apply([root.val], root.children.map(child => preorder(child)))
};
```

方法二： 迭代

```javascript
/**
 * N叉树前序遍历
 * @param {Node} root
 * @return {number[]}
 */
var preorder = function(root) {
  let result = [], current = root;
  while(current){
    result.push(current.val);
    let temp = current.children;
    if(!temp.length) return result;
    current = current.children.shift();
    let next = current;
    while (next.children.length) {
      next = next.children[next.children.length - 1];
    }
    next.children = temp;
  }
  return result;
}
```

