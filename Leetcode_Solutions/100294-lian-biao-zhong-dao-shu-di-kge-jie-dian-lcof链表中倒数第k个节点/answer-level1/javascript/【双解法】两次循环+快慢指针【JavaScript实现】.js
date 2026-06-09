
## 解法 1: 两次循环

因为要求链表倒数第 k 个节点，也就是求正数第`length - k`个节点。整体过程如下：

-   链表又是个单链表，并且没有保存长度信息。所以需要循环一次计算`length`。
-   第二次循环找到第`length - k`个节点。

时间复杂度是 O(N)，需要 2 次循环。

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// 原文地址：https://xxoo521.com/2020-01-11-dao-shu-topk/
/**
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    let length = 0;
    let node = head;
    while (node) {
        ++length;
        node = node.next;
    }

    if (k > length) {
        return null;
    }

    node = head;
    let offset = length - k;
    for (let i = 0; i < offset; ++i) {
        node = node.next;
    }
    return node;
};
```

## 解法 2: 快慢(双)指针

准备两个指针：left（慢）和 right（快）。整体过程如下：

-   right 先向右移动 k 位，此时 `index(right) - index(left) = k`
-   left 和 right 一起向右移动，直到 right 抵达边界
-   由于`index(right) - index(left) = k`，所以`index(left) = index(right) - k = length - k`。也就是 left 指针移动到了倒数第 k 个位置

时间复杂度是 O(N)，但仅需要遍历一次。空间复杂度是 O（1）

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// 原文地址：https://xxoo521.com/2020-01-11-dao-shu-topk/
/**
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    let right = head;
    for (let i = 0; i < k; ++i) {
        if (right === null) {
            // 链表长度小于k
            return null;
        }
        right = right.next;
    }

    let left = head;
    while (right) {
        left = left.next;
        right = right.next;
    }

    return left;
};
```

## 相关题目

-   [LeetCode 19. 删除链表的倒数第 N 个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
