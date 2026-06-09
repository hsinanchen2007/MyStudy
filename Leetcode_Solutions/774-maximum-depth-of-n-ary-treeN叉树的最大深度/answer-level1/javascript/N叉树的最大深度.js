```
/**
  function Node (v, childs) {
    this.v = v
    this.childs = childs
  }
*/

function maxDepth (root) {
  if (!root) {
    return 0
  }
  
  const stack = [{node: root, deep: 1}]
  let result = 1
  while (stack.length > 0) {
    let currentNode = stack.pop()
    let { node, deep } = currentNode
    let children = node.children
    result = Math.max(result, deep)
    if (children && children.length) {
      for (let i = 0; i < children.length; i++) {
        let child = children[i]
        stack.push({node: child, deep: deep + 1})
      }
    }
  }
  return result
}
```

![image.png](https://pic.leetcode-cn.com/c2381d971901f5a83207a20b663f6ec94e4735ddb2e697568ea772ad3a39202e-image.png)

不多比比， 直接看代码


吐槽一句：题目中给的是

```
/**
  function Node (v, childs) {
    this.v = v
    this.childs = childs
  }
*/

但是实际上的数据结构是特么：
真的搞我心态

/**
  function Node (v, children) {
    this.v = v
    this.children = children
  }
*/
```