### 解题思路
此处撰写解题思路

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

var swapPairs = function(head) {
    // 1. 确认 head 大于等于两个，否则返回;
    if (!head || !head.next) return head;
    // 2. 新建链表哨兵头并创建指针curr；
    let res = new ListNode(null);
    res.next = head;
    let pre = res;
    //  let [fst, snd] = [prev.next, prev.next.next];
    //     [prev.next, fst.next, snd.next] = [snd, snd.next, fst];
    //     prev = prev.next.next;
    while (pre.next != null && pre.next.next != null) {
        let fst = pre.next
        let sec = pre.next.next

        // swap
        pre.next = sec
        fst.next = sec.next
        sec.next = fst
        pre = pre.next.next
    }
    return res.next
};

// atention
1. 添加一个守卫标志
2. 找到第一个借点, 第二个借点
3. 交换 
4. 首节点要只想第二个节点, h->2 : h->2 1->2->3->4
5. 第一个节点指向3  h->2 1->3->4
6. 交换 第二个借点指向1 h->2->1->3->4
7. pre 等于 1 节点