### 解题思路
1. 通过题***环形链表1*** 我们知道可以用快慢指针来判断是否有环
2. 这时看图,设环入口点为A,快慢指针的交点为B
![截屏2019-12-14下午12.14.12.png](https://pic.leetcode-cn.com/3a86f630039e2a258e5483db8580b7d298cb9a000fd1de0092f4149b32575ed5-%E6%88%AA%E5%B1%8F2019-12-14%E4%B8%8B%E5%8D%8812.14.12.png)
3. 从图上最后的等式可看到: 快慢指针相交之后,从head再出发一个慢指针,新旧**慢指针**的交点位置将会是A点
等式左边: B+A代表旧指针从B出发再走A步.
等式右边: len+1代表链表终点的后一个位置,即环的入口.
所以从起点再出发一个新slow指针走A步之后正好与旧slow指针相交在A处.

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
 * @return {ListNode}
 */
// 1.利用快慢指针来判断是否有环
// 2.找到交点之后,用一个新的慢指针从head出发,与旧的慢指针交点就是环的入口处,详见题解
var detectCycle = function(head) {
    let fast = head;
    let slow1 = head;
    while(true) {
        if(!fast || !fast.next) return null;
        fast = fast.next.next;
        slow1 = slow1.next;
        if(slow1 === fast) {
            break;
        }
    }
    fast = head; // 将fast重置为新的慢指针
    while(fast!==slow1) {
        fast = fast.next;
        slow1 = slow1.next;
    }
    return fast;
};
```