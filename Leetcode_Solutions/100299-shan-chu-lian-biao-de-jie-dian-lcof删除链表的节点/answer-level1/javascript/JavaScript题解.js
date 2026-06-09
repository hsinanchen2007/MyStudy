### 解题思路
单链表的操作

### 代码

```javascript
var deleteNode = function(head, val) {
    let dummyNode = new ListNode(-1);
    let prev = dummyNode;
    dummyNode.next = head;
    
    while(prev.next !== null){
        if(prev.next.val === val){
            prev.next = prev.next.next;
            return dummyNode.next;
        }else{
            prev = prev.next;
        }
    }
};
```