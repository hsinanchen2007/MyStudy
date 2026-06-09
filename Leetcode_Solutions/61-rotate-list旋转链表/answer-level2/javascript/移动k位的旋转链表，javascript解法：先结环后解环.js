### 解题思路
主体思路是把链表连接成环状,计算出新head位置后，把新head之前那个元素的next取为null，这样就可以形成新链表，最后返回新head。

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
    let originhead
    if(head===null||head.next===null){
        return head;
    }else{
        originhead = head;
    }
    let length = 0;
    while(head){
        if (head.next===null){
            length += 1;
            head.next = originhead;
            break;
        }
        length += 1;
        head = head.next;
    }
    let movenum = k%length;
    let breakpoint = length-movenum-1;
    for (let i=0;i<breakpoint;i++){
        originhead=originhead.next;    
    }
    let newhead=originhead.next;
    originhead.next=null;
    return newhead;
}
```