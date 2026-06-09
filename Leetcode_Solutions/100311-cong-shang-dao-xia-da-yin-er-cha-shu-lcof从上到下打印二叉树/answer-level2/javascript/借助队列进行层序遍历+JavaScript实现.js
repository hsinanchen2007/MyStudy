
层序遍历需要使用一个队列来存储有用的节点。整体的思路如下：

-   将 root 放入队列
-   取出队首元素，将 val 放入返回的数组中
-   检查队首元素的子节点，若不为空，则将子节点放入队列
-   检查队列是否为空，为空，结束并返回数组；不为空，回到第二步

时间复杂度和空间复杂度是 O(N)。代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-02-btree-level-travel/

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var levelOrder = function(root) {
    if (!root) {
        return [];
    }

    const data = [];
    const queue = [root];
    while (queue.length) {
        const first = queue.shift();
        data.push(first.val);
        first.left && queue.push(first.left);
        first.right && queue.push(first.right);
    }

    return data;
};
```

在 Js 中没有专门的“队列”，都使用数组来实现。队列的常用操作：

-   入队：`array.push(val)`
-   出队：`array.shift()`
-   查看队首元素：`array[0]`
-   检查是否为空：`!!array.length`

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
