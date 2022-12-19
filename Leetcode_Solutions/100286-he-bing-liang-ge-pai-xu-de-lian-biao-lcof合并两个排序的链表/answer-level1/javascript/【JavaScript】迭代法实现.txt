
## 解法：迭代

设置一个“哨兵节点”叫 preHead，这会让代码写起来非常“清爽”。整体流程如下：

-   如果 pHead1 和 pHead2，均没遍历完：
    -   如果 pHead1.val <= pHead2.val，那么当前 node 的 next 指向 pHead1。并且移动 pHead1 指针。
    -   否则，当前 node 的 next 指向 pHead2，移动 pHead2 指针。
    -   移动 node 指针
    -   继续循环
-   否则，结束循环：
    -   如果 pHead1 未遍历完，node 的 next 指向 pHead1
    -   如果 pHead2 未遍历玩，node 的 next 指向 pHead2

时间复杂度是 O(N)，空间复杂度是 O(1)。代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
// 原文地址：https://xxoo521.com/2020-01-12-merge-two-sorted-lists/

/**
 * @param {ListNode} pHead1
 * @param {ListNode} pHead2
 * @return {ListNode}
 */
var mergeTwoLists = function(pHead1, pHead2) {
    if (!pHead1) {
        return pHead2;
    } else if (!pHead2) {
        return pHead1;
    }

    let preHead = new ListNode(-1);
    let node = preHead;

    while (pHead1 && pHead2) {
        if (pHead1.val <= pHead2.val) {
            node.next = pHead1;
            pHead1 = pHead1.next;
        } else {
            node.next = pHead2;
            pHead2 = pHead2.next;
        }
        node = node.next;
    }

    if (pHead1) {
        node.next = pHead1;
    } else if (pHead2) {
        node.next = pHead2;
    }

    return preHead.next;
};
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
