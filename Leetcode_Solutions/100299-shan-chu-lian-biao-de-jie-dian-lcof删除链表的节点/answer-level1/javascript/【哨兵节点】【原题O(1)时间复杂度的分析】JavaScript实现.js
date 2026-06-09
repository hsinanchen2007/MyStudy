
// ## 题目分析

// LeetCode 上和书本原题有区别，因为本题给的函数模版是：

// ```javascript
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {};
// ```

// 参数 val 是 number 类型，书本原题的 val 也是 ListNode 指针类型。

// ## 解法：哨兵节点

// 本题实现并不复杂。并且在链表问题中，通常借助哨兵节点，来简化代码。哨兵节点的用法灵活，一般是不保存任何数据的节点。

// 说了这么多，直接看代码实现吧：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
// 原文地址：https://xxoo521.com/2020-02-18-delete-list-node/

/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
    let pre = new ListNode(-1); // 哨兵节点
    pre.next = head;

    let node = pre;
    while (node.next) {
        if (node.next.val === val) {
            node.next = node.next.next;
            break;
        }
        node = node.next;
    }
    return pre.next;
};
// ```

// 从上面代码可以看到，添加哨兵节点后，所有的逻辑都收归到了 while 循环中。

// 时间复杂度是$O(N)$，空间复杂度是$O(1)$。

// ## 拓展思考：快速删除

// 和 Leetcode 不同的是，书本原题传入给函数的参数类型如下：

// ```javascript
/**
 * @param {ListNode} head
 * @param {ListNode} toDelete
 * @return {ListNode}
 */
var deleteNode = function(head, toDelete) {};
// ```

// 也就是说，如果 toDelete 参数是 ListNode 类型，那么有没有时间复杂度是$O(1)$的做法呢？

// 答案是：有。解决思路是：将 toDelete.next 的 val 和 next 指针，全都赋值给 toDelete。伪代码如下：

// ```javascript
toDelete.val = toDelete.next.val;
toDelete.next = toDelete.next.next;
// ```

// 边界情况是删除最后一个节点时，此时 toDelete.next 为 null。那么回退到普通解法。

// 代码实现如下：

// ```javascript
// 原文地址：https://xxoo521.com/2020-02-18-delete-list-node/

var deleteNode = function(head, toDelete) {
    if (!toDelete || !head) {
        return null;
    }

    if (!toDelete.next) {
        // toDelete是尾节点
        let pre = new ListNode(-1);
        pre.next = head;

        let node = pre;
        while (node.next !== toDelete) {
            node = node.next;
        }
        node.next = null;
        return pre.next;
    } else {
        toDelete.val = toDelete.next.val;
        toDelete.next = toDelete.next.next;
        return head;
    }
};
// ```

// 空间复杂度是$O(1)$,时间复杂度是：

// $$
// O(T)
// = \frac{O(N) + O(1) * (n - 1)}{n}
// = O(1)
// $$

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
