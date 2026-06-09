### 深度优先搜索

- 对 ``二叉树`` 进行 ``深度优先搜索``，把每层的节点值保存到数组中
- 搜索结束之后，对每一层求平均值

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
 * @return {number[]}
 */
var averageOfLevels = function(root) {
    const helper = (root, level) => {
        // 如果为空那么结束递归
        if (!root) {
            return
        }
        // 如果当前层还没赋值，那么直接赋值 [root.val]
        // 否则 push root.val
        if (!nodes[level]) {
            nodes[level] = [root.val]
        } else {
            nodes[level].push(root.val)
        }
        // 递归左子树
        helper(root.left, level + 1)
        // 递归右子树
        helper(root.right, level + 1)
    }
    // 节点值保存到这个数组（将来是二维）
    let nodes = []
    // 递归
    helper(root, 0)
    // 求已保存好的每层节点的平均值
    return nodes.map((node) => {
        return node.reduce((prev, curr) => prev + curr) / node.length
    })
};
```

#### 优化空间复杂度

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
 * @return {number[]}
 */
var averageOfLevels = function(root) {
    const helper = (root, level) => {
        // 如果为空那么结束递归
        if (!root) {
            return
        }
        // 如果没有统计过，那么设置初始值
        // 否则累加 root.val
        if (!sumMap.has(level)) {
            sumMap.set(level, root.val)
            countMap.set(level, 1)
        } else {
            let sum = sumMap.get(level)
            let count = countMap.get(level)
            sumMap.set(level, sum + root.val)
            countMap.set(level, count + 1)
        }
        // 递归左子树
        helper(root.left, level + 1)
        // 递归右子树
        helper(root.right, level + 1)
    }
    // 统计二叉树每层节点的和
    let sumMap = new Map()
    // 统计每层二叉树的节点数
    let countMap = new Map()
    // 存放结果
    let res = []
    // 递归
    helper(root, 0)
    // 计算二叉树每层节点的和
    for (let [key, val] of sumMap) {
        res[key] = val / countMap.get(key)
    }
    return res
};
```


### 广度优先搜索

- 利用 ``队列`` 对 ``二叉树`` 进行逐层遍历
- 每一层遍历结束之后都算一次平均值

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
 * @return {number[]}
 */
var averageOfLevels = function(root) {
    let queue = [root]
    let res = []
    // 队列值不为空则循环继续
    while (queue.length) {
        // 计算一层节点的个数
        let count = 0
        // 计算总和
        let sum = 0
        // 临时数组，用来保存下一层的节点
        let temp = []
        while (queue.length) {
            // 解构赋值
            let { val, left, right } = queue.shift()
            sum += val
            count++
            // left 不为空就把 left push 到 temp 中
            if (left) {
                temp.push(left)
            }
            // right 不为空就把 right push 到 temp 中
            if (right) {
                temp.push(right)
            }
        }
        // 计算平均值并 push 到 res 中
        res.push(sum / count)
        // 这里需要对 temp 做一次浅拷贝
        // 避免重新对 temp 赋值时影响到 queue
        queue = temp.slice()
    }
    // 返回结果
    return res
}
```

