## 思路

不知道叫什么方法，姑且认为是记忆化搜索吧。同时我感觉这道题很好，更像是考察实现深拷贝，而非算法。

基本思路：递归，可以看作是对一个图的遍历。对于遍历过的结点，用哈希表记录：`旧结点 => 新结点`这个映射。

## 代码

```js
var copyRandomList = function (head) {
  const mapping = new Map();

  // 递归函数
  // 有点Top-down DP那味儿！（其实就是）
  function copy(node) {
    if (!node) return node; // 空结点
    if (mapping.has(node)) return mapping.get(node); // 取缓存

    const res = new Node();
    mapping.set(node, res); // 先放缓存
    res.val = node.val;
    res.next = copy(node.next); // 结点，要递归
    res.random = copy(node.random); // 结点，要递归
    return res;
  }

  return copy(head);
};
```