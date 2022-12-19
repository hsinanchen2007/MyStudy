
## 思路

用一个哈希表表示映射关系：键是原节点，值是复制的节点。

整体算法流程是：

-   第一次遍历，复制每个节点和 next 指针，并且保存“原节点-复制节点”的映射关系
-   第二次遍历，通过哈希表获得节点对应的复制节点，更新 random 指针

## 代码实现

使用 ES6 的`Map`，可以直接将对象作为键值。

JavaScript 代码实现：

```javascript
// ac地址：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
// 原文地址：https://xxoo521.com/2020-02-05-link-copy/

/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */
/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
    if (!head) {
        return null;
    }
    const map = new Map();
    let node = head; // 当前节点
    const newHead = new Node(node.val);
    let newNode = newHead; // 当前节点的copy
    map.set(node, newNode);

    while (node.next) {
        newNode.next = new Node(node.next.val);
        node = node.next;
        newNode = newNode.next;
        map.set(node, newNode);
    }

    newNode = newHead;
    node = head;
    while (newNode) {
        newNode.random = map.get(node.random);
        newNode = newNode.next;
        node = node.next;
    }

    return newHead;
};
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
