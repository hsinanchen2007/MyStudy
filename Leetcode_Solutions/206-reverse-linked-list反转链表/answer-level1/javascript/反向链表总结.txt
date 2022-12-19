### 解题思路
此处撰写解题思路
思路如何让 next 指针反向问题
1. next 反向指需要存储正向当前节点的下一个结点及：tmp = cur.next;
2. 第二步则可以让 next 指向反向指向 pre.
3. 第三步pre, 和 cur 都需要前进一步进行重复以上步骤。则为：pre = cur; cur = tmp;
 
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
 * 
 */
var reverseList = function(head) {
    let pre = null;  
    let cur = head;
    while(cur) {
        let tmp = cur.next;
        cur.next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
};
```