### 解题思路

levelOrderToArrayString 这个函数将树序列化成字符串。

### 代码

```javascript
levelOrderToArray = function (root) {
    if (!root)
        return [];
    let queue = [];
    const ans = [];
    queue.push(root);
    while (queue.length !== 0) {
        if (!queue.some(item => item !== null))
            break;
        const tmp = queue.shift();
        if (!tmp) {
            ans.push(null);
            continue;
        }
        queue.push(tmp.left, tmp.right);
        ans.push(tmp.val);
    }
    return ans;
};
levelOrderToArrayString = function (o) {
    if (!o)
        return '';
    return levelOrderToArray(o)
        .reduce((ans, item) => (ans += ',' + (item === null ? 'null' : item)), '')
        .slice(1);
};
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function (root) {
    if (!root)
        return [];
    const trees = new Map();
    const ans = [];
    const helper = (node) => {
        if (!node)
            return null;
        const uid = {
            val: node.val,
            left: helper(node.left),
            right: helper(node.right)
        };
        if (!trees.has(levelOrderToArrayString(uid)))
            trees.set(levelOrderToArrayString(uid), 1);
        else if (trees.get(levelOrderToArrayString(uid)) === 1) {
            ans.push(uid);
            trees.set(levelOrderToArrayString(uid), 2);
        }
        return uid;
    };
    helper(root);
    return ans;
};
```

### typescript 解法

```typescript
export const levelOrderToArray = function<T>(
  root: IBinaryTreeNode<T> | null
): (T | null)[] {
  if (!root) return []
  let queue: (IBinaryTreeNode<T> | null)[] = []
  const ans: (T | null)[] = []
  queue.push(root)
  while (queue.length !== 0) {
    if (!queue.some(item => item !== null)) break
    const tmp = queue.shift()
    if (!tmp) {
      ans.push(null)
      continue
    }
    queue.push(tmp.left, tmp.right)
    ans.push(tmp.val)
  }
  return ans
}

export const levelOrderToArrayString = function<T>(
  o: IBinaryTreeNode<T> | null
): string {
  if (!o) return ''
  return levelOrderToArray(o)
    .reduce((ans, item) => (ans += ',' + (item === null ? 'null' : item)), '')
    .slice(1)
}
const findDuplicateSubtrees = function(
  root: IBinaryTreeNode<number> | null
): IBinaryTreeNode<number>[] {
  if (!root) return []
  const trees = new Map()
  const ans: IBinaryTreeNode<number>[] = []
  const helper = (
    node: IBinaryTreeNode<number> | null
  ): IBinaryTreeNode<number> | null => {
    if (!node) return null
    const uid: IBinaryTreeNode<number> = {
      val: node.val,
      left: helper(node.left),
      right: helper(node.right)
    }
    if (!trees.has(levelOrderToArrayString(uid)))
      trees.set(levelOrderToArrayString(uid), 1)
    else if (trees.get(levelOrderToArrayString(uid)) === 1) {
      ans.push(uid)
      trees.set(levelOrderToArrayString(uid), 2)
    }
    return uid
  }
  helper(root)
  return ans
}
```