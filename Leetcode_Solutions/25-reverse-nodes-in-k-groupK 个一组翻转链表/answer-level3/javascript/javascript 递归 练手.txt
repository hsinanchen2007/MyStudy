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
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    // 递归调用reverseKGroup
    // 获得以k为单位的 链表
    let len = 1;
    let newHead = head;
    let newTemp = null;
    let p = null;
    while( len < k && head!=null ){
        len++;
        head = head.next;
    }
    if( head === null ){
        return newHead;
    }
    p = head.next;
    head.next = null;
    newTemp = reverseKGroup(p, k);
    let  resultHead = reverseList(newHead);

    newHead.next = newTemp;
    
    // resultHead 只做返回
    return resultHead;
};
// 写一个函数 reverse 一组 
function reverseList(h){
    if( h === null || h.next === null ){
        return h;
    }
    let temp = null;
    let newList = null;
    temp = h;
    h = h.next;
    newList = reverseList(h);
    h.next = temp;
    temp.next = null;
    return newList;
}
```