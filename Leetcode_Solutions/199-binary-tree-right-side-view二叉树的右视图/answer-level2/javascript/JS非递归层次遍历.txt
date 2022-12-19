```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    if (!root) {
        return [];
    }
    const queue = [root];
    let length = 1;
    const arr = [];
    while (queue.length > 0) {
        let currLength = 0;
        for (let i = 0; i < length; i++) {
            const node = queue.shift();
            if (i === 0) {
                arr.push(node.val);
            }
            if (node.right) {
                queue.push(node.right);
                currLength++;
            }
            if (node.left) {
                queue.push(node.left);
                currLength++;
            }
        }
        length = currLength;
    }
    return arr;
};
```

还是使用层次遍历来搞，
层次遍历我通常用以下这个模板
```
if (!root) {
  return [];
}
const queue = [root];
let length = 1;
const arr = [];
while (queue.length > 0) {
  const currArr = [];
  let currLength = 0;
  for (let i = 0; i < length; i++) {
      const node = queue.shift();
      // 做逻辑
      // ...
      if (node.left){
          queue.push(node.left);
          currLength++;
      }
      if (node.right) {
          queue.push(node.right);
          currLength++;
      }
  }
  // 赋值当前length
  length = currLength;
}
return arr;
```

回到当前这道题目，套用模板。
这题优先的是右节点，因此率先把右节点放入，再放左节点。
队列返回时候，取第一个放入数组中即可。
