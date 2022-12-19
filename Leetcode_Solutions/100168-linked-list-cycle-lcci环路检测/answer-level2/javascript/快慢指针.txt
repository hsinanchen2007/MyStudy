### 解题思路
#### 寻找环：
- 绕圈跑，跑得快的和跑得慢的同时跑，跑得慢的早晚要被跑得快的追上；
- 跑直线，跑得快的比跑得慢的早到达终点

#### 寻找入口
- 见注释

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
var detectCycle = function(head) {
    // 如果只有一个节点，或者没有环，就返回null
    if (!head || !head.next) return null;
    let fast = slow = head;
    /**
     * 因为是单链表，如果存在环的话，一定是最后一个节点的指针指向其中的某一个节点
     * 所以，由于环的存在，快慢指针一定会相遇
     * 类似于操场跑圈圈，跑的快的和跑的慢的，跑得快的早晚会超跑得慢的一圈
     * 并在某个节点相遇
     */
    while (fast && fast.next) {
        fast = fast.next.next;
        slow = slow.next;
        if (fast == slow) {
            break;
        }
    }
    // 不是一个环，就没必要找入口了，直接返回
    if (!fast || !fast.next) return null;
    /**
     * 一个从头节点开始，一个从相遇节点开始
     * 因为：fast的移动速度是slow的两倍，则相同的时间内，fast移动的距离是slow的两倍
     * 设：s为slow移动的距离，f为fast移动的距离
     * 则：f=2s
     * 假设：头节点到入口节点的距离为x，入口节点到相遇节点的距离为y（单向），环的周长为r，
     * 设：n为f在环里面绕的圈数
     * 则：s=x+y, f=x+y+n*r
     * 将上式带入f=2s后，经化简可得
     * x=n*r-y, 其中n*r为整数圈数的距离
     * 因为：整数圈数无论跑多少圈，都会回到原点，不妨我们另n=1
     * 则：x=r-y
     * 所以：从头节点开始和从相遇节点开始移动，他们移动一圈的距离是相等的
     * （从头节点移动的，移动距离为x；从相遇节点开始移动，移动距离为r-y）
     * 所以：当他们移动相同的距离后，一定会在入口点相遇
     */
    fast = head;
    while (fast) {
        if (fast == slow) {
            break;
        }
        fast = fast.next;
        slow = slow.next;
    }
    return fast;
};
```