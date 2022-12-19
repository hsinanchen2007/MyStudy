### 解题思路
> 旋转链表，有点类似于我们小时候玩的丢手绢，丢手绢的同学，他可以跑半圈就丢到你的后面，也可以跑很多圈再丢到你的后面

#### 丢手绢分四步进行
- 所有同学先站成一排
- 然后首位相接，围城一个圈
- 丢手绢的同学开始绕着跑圈
- 丢到某个同学后面，这个同学从队伍中出来，这时候圈就断掉了

与丢手绢类似，这道题目也是需要找一个合适的位置，把它断开。废话不多说，详细的思路都在代码里。
#### 标题
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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if (head == null) {
        // 空链表特殊处理
        return head;
    }
    let curr = head;
    // 排除了空链表，则最少有一个，从1开始记数
    let len = 1;
    while (curr.next) {
        curr = curr.next;
        ++len;
    }
    // 变成一个环
    curr.next = head;
    /**
     * 当k<len时，要把倒数第k个(正数第len-k+1个)和倒数第k+1个(正数第len-k个)之间的链截断
     * 并将倒数第k个(正数第len-k+1个)作为新链表表头
     * 当k>len时，倒数第k个则变成了倒数第k%len个了（因为现在是个环，所以转一圈又会从头开始）
     * 因为：无论k>len或k<len，k%len的值都时k<len时的k，且倒数第k+1个是倒数第k个的前驱
     * 所以：我们要找到需要截断的元素就是倒数第k+1个，即找到正数的第len-(k%len)个元素
     * 所以：要移动的次数为len-(k%len)-1次（从头移动一次，可以找到第二个，要找第n个，则需要从头移动n-1次）
     */
    let d = len - (k % len) - 1;
    curr = head;
    while (d > 0) {
        curr = curr.next;
        --d;
    }
    // 先保存倒数第k个作为头部
    let tempHead = curr.next;
    // 断开链接
    curr.next = null;
    return tempHead;
};
```