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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
// 转换链表为数组
function transform(l) {
    let arr = [];
    if(l !== null){
        arr.push(l.val);
        if(l.next !== null){
            arr = arr.concat(transform(l.next));
        }
    }
    // console.log('arr', arr);
    return arr;
}
var addTwoNumbers = function(l1, l2) {
    const a = transform(l1);
    const b = transform(l2);
    const l = Math.max(a.length, b.length);
    console.log('l', l);
    if(a.length < l) {
       for(let i = a.length; i < l; i += 1){
        a[i] = 0;
      }
    }
    if(b.length < l) {
       for(let i = b.length; i < l; i += 1){
        b[i] = 0;
      }  
    }
    let c = [];
    for(let i = 0; i < l + 1; i+=1){
        c[i] = 0;
    }
    for(let i = 0 ; i < l; i+=1) {
        let num = a[i] + b[i];
        if(c[i] + num < 10){
            c[i] = c[i] + num;
        } else {
            c[i] = (c[i] + num)%10;
            c[i+1] = c[i+1] + 1;
        }
    }
    if(c[l] === 0) {
        c.pop();
    }
    console.log('listArr', c);
    const l3 = new ListNode()
    let pointer = l3;
    for(let i = 0; i< c.length; i+=1){
        if(i < c.length) {
            pointer.next = new ListNode(c[i])
            pointer = pointer.next;
        } else {
            pointer.next = new ListNode(c[i])
        }
    }
    return l3.next;
};
```