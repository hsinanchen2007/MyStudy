### 解题思路
根元素，标记index是0,根元素的left和right节点的index是1，依次类推

### 代码

```javascript
  var levelOrder = function (node) {
    const res = [];
    if (node) {
      node.index = 0;
      const list = [node];
      while (list.length) {
        let node = list.shift(), index = node.index;
        ((res[index] = res[index] || []), res[index]).push(node.val);
        index++;
        if (node.left) list.push((node.left.index = index, node.left));
        if (node.right) list.push((node.right.index = index, node.right));
      }
    }
    return res;
  }
```