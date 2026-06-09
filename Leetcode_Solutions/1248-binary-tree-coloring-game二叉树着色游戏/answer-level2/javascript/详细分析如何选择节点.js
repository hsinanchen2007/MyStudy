![702fa9c7bbdb5b3516b2c8fb55c8d6470ff923cc741acf678bcde4d3ed8d69f4.png](https://pic.leetcode-cn.com/669f2de1b8a65d7bd4e614ef6befb83a634d74c6c8509dc531c5a3fd2b833381-702fa9c7bbdb5b3516b2c8fb55c8d6470ff923cc741acf678bcde4d3ed8d69f4.png)
- 如果3号节点将二叉树分成了三个部分
- 3号节点的父节点那个部分  左子树  右子树
- 在3号节点的父节点那个部分  任意选择一个节点  那个节点能够收益最大化  就应该选择那个节点
- 因为每次只能选择相邻的节点  所以如果选择3号节点的父节点  那么在3号节点的父节点那个部分的所有节点都属于它 显然是最大的
- 此时也就失去了3号节点的左子树  右子树部分的节点
- 同理应该选择3号节点的左右子节点 对应在各自部分中的节点数量最多
- 因此这三种情况 涵盖了所有的节点选择  并且取出每种情况中节点数量最多的点  只要有一个符合要求 那么就为true 否则为false
```
var btreeGameWinningMove = function (root, n, x) {
  let getChildCount = function (root) {
    if (!root) return 0;
    return 1 + getChildCount(root.left) + getChildCount(root.right)
  }
  let fundNode = function (root) {
    if (!root) return false;
    if (root.val === x) {
      let left = getChildCount(root.left)
      let right = getChildCount(root.right)
      return ((left > n / 2) || (right > n / 2) || ((n - 1 - left - right) > n / 2)) ? 1 : 2
    }
    return fundNode(root.left) || fundNode(root.right);
  }
  return fundNode(root) === 1;
};
```
