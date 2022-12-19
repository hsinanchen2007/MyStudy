### 解题思路
先 DFS 获取到目标节点，过程记录 parent 节点。
写一个向下获取到 node 的距离为 k 的所有节点的方法。
然后先向下获取目标节点距离 k 的所有节点，再向上递归获取目标节点的 parent 节点距离 (k - 1) 的所有节点。
要把不是正解的节点记录一下，因为递归的过程中有可能会再次获取到这个节点。

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} K
 * @return {number[]}
 */

var distanceK = function (root, target, K) {
  var findTarget = false;
  var result = [];
  var paths = [];

  //  先 DFS 获取到目标节点.
  function findTargetNode(_root) {
    if (!!findTarget || !_root || typeof _root.val !== "number") return;
    if (_root.val === target.val) findTarget = true;
    if (!findTarget) {
      if (_root.left && typeof _root.left.val === "number") {
        _root.left.parent = _root;
        findTargetNode(_root.left);
      }
      if (_root.right && typeof _root.right.val === "number") {
        _root.right.parent = _root;
        findTargetNode(_root.right);
      }
    }
  }

  //  向下 DFS. 获取到 node 的距离为 k 的所有节点.
  function getKFromNode(node, k) {
    if (!node || typeof node.val !== "number") return;
    if (k > 0) {
      paths.push(node);
      getKFromNode(node.left, k - 1);
      getKFromNode(node.right, k - 1);
    } else {
      if (!!node && !paths.includes(node) && typeof node.val === "number")
        result.push(node.val);
    }
  }

  findTargetNode(root);

  var _K = K;
  var targetNode = target;
  while (_K > -1) {
    getKFromNode(targetNode, _K);
    paths.push(targetNode);
    _K--;
    if (!!targetNode.parent) {
      targetNode = targetNode.parent;
    } else {
      _K = -1;
    }
  }

  return result;
};
```