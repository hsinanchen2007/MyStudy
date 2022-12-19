### 解题思路
作为一个新手这个问题想了很久，链表类似于一种嵌套结构一层套一层，用while循环是为了保证当前的cur不为null，整体的思路是让正常的下一个变成之前的也就是cur.next = pre 把指针转向，然后cur和pre提前进行下一次循化也就是cur = next ,pre = cur ,然后下次循化就可以在新的cur的基础上进行，如果cur为null那就结束循化，如题所示最后的为null，最后在循化结束返回pre，pre存储着所有指针转向的结果

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
var reverseList = function(head) {
    if(!head) return null
    let cur = head; 
    let pre = null;
    while(cur){
        let next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
        
    }
    return  pre

};
```