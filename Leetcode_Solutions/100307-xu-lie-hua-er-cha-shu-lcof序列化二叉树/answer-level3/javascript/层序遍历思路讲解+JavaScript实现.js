// ## 序列化二叉树思路

// 使用广度优先（BFS）遍历所有节点（包括空节点），整体流程如下：

// 1. 初始化字符串 res
// 2. 初始化队列 queue，将 root 放入队列
// 3. 检查队列是否为空：
//     - 队列不为空：取出队首节点，如果节点为 null，那么 res 更新为 res + '#,'；如果节点不是 null，那么 res 更新为 res + val，并且将节点的左右节点依次加入 queue。继续循环。
//     - 队列为空：结束循环
// 4. 返回"[" + res + "]"

// ```
    1
   / \
  2   3
     / \
    4   5
// ```

// 以上面这棵二叉树为例，它的序列化结果是`"[1,2,3,#,#,4,5,#,#,#,#]"`

// 序列化的代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-13-serialize-and-deserialize-btree/

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    if (!root) {
        return "[]";
    }

    let res = "";
    let node = root;
    const queue = [node];
    while (queue.length) {
        const front = queue.shift();
        if (front) {
            res += `${front.val},`;
            queue.push(front.left);
            queue.push(front.right);
        } else {
            res += "#,";
        }
    }

    res = res.substring(0, res.length - 1); // 去掉最后一个逗号

    return `[${res}]`;
};
// ```

// ## 反序列化二叉树思路

// 以前面的二叉树为例，反序列话就是将字符串`"[1,2,3,#,#,4,5,#,#,#,#]"`重新还原成原来的二叉树。

// 反序列化流程如下：

// -   去掉字符串 res 前后的`[`和`]`，并将其按照`,`逗号切分得到数组 nodes
// -   初始化队列 queue，放入 nodes 的第一个值对应的节点，nodes 弹出第一个值
// -   检查队列是否为空：
//     -   队列不为空。从 queue 取出队首元素。从 nodes 中取出第一个值和第二值，依次处理。继续循环。
//     -   队列为空。结束循环。
// -   返回根节点。

// **反序列化函数的设计关键是：数组 nodes 取出元素的顺序和原二叉树层序遍历的顺序是对应的。**

// 反序列的函数实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-13-serialize-and-deserialize-btree/

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (data.length <= 2) {
        return null;
    }

    const nodes = data.substring(1, data.length - 1).split(",");
    const root = new TreeNode(parseInt(nodes[0]));
    nodes.shift();

    const queue = [root];
    while (queue.length) {
        const node = queue.shift();
        // 第一个是左节点，节点为空，直接跳过
        const leftVal = nodes.shift();
        if (leftVal !== "#") {
            node.left = new TreeNode(leftVal);
            queue.push(node.left);
        }
        // 第二个是右节点，节点为空，直接跳过
        const rightVal = nodes.shift();
        if (rightVal !== "#") {
            node.right = new TreeNode(rightVal);
            queue.push(node.right);
        }
    }

    return root;
};
// ```

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
