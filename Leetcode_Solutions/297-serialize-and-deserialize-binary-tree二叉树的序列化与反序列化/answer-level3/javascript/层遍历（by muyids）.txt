### 解题思路

层遍历

### 代码

```javascript
/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function (root) {
    let s = []
    if (!root) return s.join(',');
    let q = [root]
    while (q.length > 0) {
        let k = q.length;
        for (let m = 0; m < k; m++) {
            let node = q.shift()
            if (node == null) {
                s.push('null')
            } else {
                s.push(node.val)
                q.push(node.left)
                q.push(node.right)
            }
        }
    }
    return s.join(',');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function (data) {
    let nodes = data.split(',').map(v=>{
        if (v == 'null'){
            return null
        }
        return v
    })
    if (nodes.length == 1 && nodes[0] == '') {
        return null
    }
    let root = new TreeNode(nodes[0])
    let q = [root]
    let i = 1
    while (q.length > 0 && i < nodes.length) {
        let cur = q.shift()
        if (cur == null) {
            continue
        }
        if (i == nodes.length) break
        if (nodes[i] == null) {
            cur.left = null
        } else {
            cur.left = new TreeNode(nodes[i])
            q.push(cur.left)
        }
        i++

        if (i == nodes.length) break
        if (nodes[i] == null) {
            cur.right = null
        } else {
            cur.right = new TreeNode(nodes[i])
            q.push(cur.right)
        }
        i++

    }
    return root
};



```