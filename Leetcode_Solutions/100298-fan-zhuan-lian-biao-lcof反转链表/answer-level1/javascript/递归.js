### 解题思路
看代码

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
    if(head == null || head.next == null){
        return head
    }
    const current = reverseList(head.next);
    //例如，1，2，3，4，5,null
    //current是5
    //head是4
    //head.next 是 5
    //head.next.next 就是5指向的指针，指向当前的head（4）
    //5-4-3-2-1-null
    head.next.next = head;
    //注意把head.next设置为null，切断4链接5的指针
    head.next = null
    //每层递归返回当前的节点，也就是最后一个节点。（因为head.next.next改变了，所以下一层current变4，head变3）
    return current;
};
```