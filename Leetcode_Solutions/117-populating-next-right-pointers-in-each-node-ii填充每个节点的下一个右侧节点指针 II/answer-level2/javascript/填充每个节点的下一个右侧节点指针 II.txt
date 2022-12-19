### 解题思路
利用层级遍历，找出每一级的遍历顺序。节点的next 指针指向 该节点所在层的下一个节点，如果不存在，则指向null

### 代码

```javascript
var connect = function(root) {
  if (!root) return null;

  const queue = [root];
  let cur;
  let level;

  while (queue.length) {
    level = queue.length;
    let i = 0;
    const temp = [];

    while (i++ < level) {
      cur = queue.shift();

      temp.push(cur);

      cur.left && queue.push(cur.left);
      cur.right && queue.push(cur.right);
    }

    temp.forEach((v, k) => {
      v.next = temp[k + 1] || null;
    });
  }

  return root;
};
```