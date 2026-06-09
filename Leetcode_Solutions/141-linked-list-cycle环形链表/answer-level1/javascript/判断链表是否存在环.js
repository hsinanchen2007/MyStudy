### 解题思路

可以想象，单链表就像一条平行直线，如果没有环，肯定会有个 tail 节点，next 指向 null。如果出现了环，在循环遍历的时候就会出现重复的值。

解法：

- 遍历链表 0.5 秒，可以找到 tail 节点，就没有环 （最笨的方法）
- 标记法，没遍历一个节点，标记 head.flag = 1；时间复杂度：O(n)
- 用 Set 集合来存储每次遍历的节点，遍历的次数和 Set 集合元素个数不一致时，就表示出现了环（或者用数组判重的方式）。时间复杂度：O(n)，空间复杂度 O(n)
- 龟兔赛跑，如果跑道出现环，兔子总会重新遇到乌龟。用快慢指针遍历链表，快慢指针会重新相遇。（最优解），时间复杂度：O(n)，空间复杂度 O(1)


### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
    //边界条件
    if (head == null || head.next == null) {
        return false;
    }
    // 快慢指针
    let slow = head;
    let fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            return true;
        }
    }
    return false;
};
```

## 总结

关于链表数据结构笔记：[https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list](https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list)

![fe-insights.jpg](https://pic.leetcode-cn.com/936dcb02e5f5636a779abf809514677985a18b20667952e608527e2026f1c3a2-fe-insights.jpg)
