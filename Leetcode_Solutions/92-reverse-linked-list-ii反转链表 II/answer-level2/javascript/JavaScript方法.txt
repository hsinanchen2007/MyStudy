### 解题思路
此处撰写解题思路
主要注意区间的头尾节点(start, end)和距离区间最近的两个节点(first, second)，区间反转之后，要把first、second指向正确的位置。
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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    let length = n-m+1;
    if(length == 1){
        return head;
    }
    let pre=null, cur=head;
    for(let i=1;i<m;i++){
        pre = cur;
        cur=cur.next;
    }
    let first = pre,second = cur;
    let reverse = (pre, cur, length)=>{
        if(length == 0){
            second.next = cur;
            if(m == 1){
                return pre;
            }
            first.next = pre;
            return head;
        }
        let next = cur.next;
        cur.next=pre;
        return reverse(cur, next, length - 1);
    }
    return reverse(pre, cur, length);
};
```