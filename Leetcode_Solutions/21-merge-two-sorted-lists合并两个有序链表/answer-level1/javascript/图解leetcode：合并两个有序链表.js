// ### 解题思路
// **确定解题的数据结构：** 单链表

// **确定解题思路：** 从链表头开始比较，`l1` 与 `l2` 是有序递增的，所以比较 `l1.val` 与 `l2.val` 的较小值就是合并后链表的最小值，次小值就是小节点的 `next.val` 与大节点的 `val` 比较的较小值，依次递归，直到递归到 `l1` `l2` 均为 `null`

// **画图实现：** 画图帮助理解一下

// ![](https://pic.leetcode-cn.com/a918cadaf04feddd5429bd4cdc9ef259cdcae6126e194e0284d86287a5ba3006.png)

// **确定边界条件：** 当递归到任意链表为 `null` ，直接将 `next` 指向另外的链表即可，不需要继续递归了

// ### 代码

// ```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function mergeTwoLists(l1, l2) {
    if(l1 === null) {
        return l2
    }
    if(l2 === null) {
        return l1
    }
    if(l1.val <= l2.val) {
        l1.next = mergeTwoLists(l1.next, l2)
        return l1
    } else {
        l2.next = mergeTwoLists(l2.next, l1)
        return l2
    }
}
// ```


// ### 认识更多的前端道友，一起进阶前端开发

// 前端算法集训营第一期免费开营啦🎉🎉🎉，免费哟！

// 在这里，你可以和志同道合的前端朋友们（800+）一起进阶前端算法，从0到1构建完整的数据结构与算法体系。

// 在这里，瓶子君不仅介绍算法，还将算法与前端各个领域进行结合，包括浏览器、HTTP、V8、React、Vue源码等。

// 在这里，你可以每天学习一道大厂算法题（阿里、腾讯、百度、字节等等）或 leetcode，瓶子君都会在第二天解答哟！

// 更多福利等你解锁🔓🔓🔓！

// 扫码关注公众号「前端瓶子君」内回复「算法」即时加入😊😊😊
// ![](https://pic.leetcode-cn.com/0693e3578144b3f79b70f3e98fdac525ff6c859af2a1e1e8b8da8b81a0e1e6cb.png)
