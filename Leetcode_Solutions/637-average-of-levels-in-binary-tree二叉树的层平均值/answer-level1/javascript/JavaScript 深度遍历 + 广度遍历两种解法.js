
// [leetcode](https://github.com/yeyan1996/leetcode) 记录了我刷题的过程( JavaScript 版本)，希望各位赏个 star 👏

// ## 广度遍历解法
// ```javascript
 var averageOfLevels = function(root) {
  let res = [];
  if (!root) return res;
  let queue = [root];
  while (queue.length) {
    let length = queue.length;
    let sum = 0;
    for (let i = 0; i < length; i++) {
      let node = queue.shift();
      sum += node.val;
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
    res.push(sum / length);
  }
  return res;
}; 
// ```
// 最简单也是性能效率的最优解法，利用队列逐层遍历二叉树，然后计算当前层数所有元素的平均值

// ## 深度遍历解法

// ```javascript
var averageOfLevels = function(root) {
  let res = [];
  if (!root) return res;
  const traverse = (node, depth) => {
    (res[depth] || (res[depth] = [])).push(node.val);
    if (node.left) traverse(node.left, depth + 1);
    if (node.right) traverse(node.right, depth + 1);
  };
  traverse(root, 0);
  return res.map(item => item.reduce((pre, cur) => pre + cur) / item.length);
};
// ```

// 深度遍历解法，前序遍历二叉树，每次递归的时候记录当前的深度，根据深度来将当前节点放入数组的对应的位置

// 遍历完毕会得到一个二维数组，即数组每个元素也是一个数组，保存了当前层数的所有节点

// 将二维数组的每个元素做归并求平均值即可