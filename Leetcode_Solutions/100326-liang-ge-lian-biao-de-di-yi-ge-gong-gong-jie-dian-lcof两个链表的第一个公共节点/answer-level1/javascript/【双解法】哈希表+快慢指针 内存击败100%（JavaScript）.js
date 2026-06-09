
// ## 解法 1: 遍历+哈希表记录

// 比较容易想到的思路：

// -   开辟哈希表 map。key 是节点，value 是 boolean，代表节点是否出现过
// -   对 list1 进行遍历，设置 `map[节点]=true`
// -   对 list2 进行遍历，如果节点在 map 中出现过，那么说明这是两个链表的公共节点，返回

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
// 原文地址：https://xxoo521.com/2020-03-12-list-node/
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    const map = new Map();
    let node = headA;
    while (node) {
        map.set(node, true);
        node = node.next;
    }

    node = headB;
    while (node) {
        if (map.has(node)) return node;
        node = node.next;
    }
    return null;
};
// ```

// 时间复杂度是$O(N)$，空间复杂度是$O(N)$。

// ## 解法 2: 快慢指针

// 题目提示了，空间复杂度可以降低到$O(1)$。这时候不能用哈希表，可以使用快慢指针的思路来处理。整体思路如下：

// -   遍历得到两个链表的长度，以及长度差 diff
// -   将慢指针 slow 指向较长链表，快指针 fast 指向较短链表
// -   slow 向前移动 diff 个距离
// -   slow 和 fast 同时向前移动，每次移动一个距离。若存在公共节点，那么它们一定会遇上。

// 代码实现是：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
// 原文地址：https://xxoo521.com/2020-03-12-list-node/

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let node = headA;
    let lengthA = 0;
    while (node) {
        ++lengthA;
        node = node.next;
    }
    if (!lengthA) return null;

    node = headB;
    let lengthB = 0;
    while (node) {
        ++lengthB;
        node = node.next;
    }
    if (!lengthB) return null;

    let diff = 0,
        slow,
        fast;
    if (lengthA > lengthB) {
        slow = headA;
        fast = headB;
        diff = lengthA - lengthB;
    } else {
        slow = headB;
        fast = headA;
        diff = lengthB - lengthA;
    }

    while (diff--) {
        slow = slow.next;
    }

    while (slow !== fast) {
        slow = slow.next;
        fast = fast.next;
    }

    return slow;
};
// ```

// 时间复杂度是$O(N)$，空间复杂度是$O(1)$。效果也蛮好的，时间击败 95.49%，内存击败 100%。截图如下：

// ![](https://pic.leetcode-cn.com/6a80d7dbb9a5ae27e52da81965ebe23d67a570e060e42fca352accf29ffecd59.jpg)

// ## 更多资料

// **整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
