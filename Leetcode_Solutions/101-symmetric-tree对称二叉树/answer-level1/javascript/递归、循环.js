```
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetricRecursive = function(root) {
  const nodeIsSymmetric = function(s, t) {
    if (
      s &&
      t &&
      s.val === t.val &&
      nodeIsSymmetric(s.left, t.right) &&
      nodeIsSymmetric(s.right, t.left)
    )
      return true
    return s === null && t === null
  }

  if (!root) return true
  return nodeIsSymmetric(root.left, root.right)
}

var isSymmetricDFS = function(root) {
  if (!root) return true
  const stack = []

  stack.push(root.left, root.right)

  while(stack.length > 0) {
    const s = stack.pop()
    const t = stack.pop()

    if (!s && !t) continue
    if (!s || !t) return false
    if (s.val !== t.val) return false
    stack.push(s.left, t.right, s.right, t.left)
  }

  return true
}
```
