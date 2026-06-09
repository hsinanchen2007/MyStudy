### 解题思路

创建新链表的方式 , 通过比较 l1 / l2 两个节点来判断该将那个放入新链表中

while 条件为 l1 或 l2 链表到底 , 之后通过或运算来将有值的链表节点接上

最后由于一开始初始化的时候给了一个 null 的节点 , 所以需要通过 .next 剔除

### 代码

```javascript
var mergeTwoLists = function(l1, l2) {
    let newLinkedList = new ListNode(null);
    let head = newLinkedList;

    while(l1 && l2) {
        if (l1.val < l2.val) {
            head.next = l1;
            l1 = l1.next;
            head = head.next;
        } else {
            head.next = l2;
            l2 = l2.next;
            head = head.next;
        }
    }

    head.next = l1 || l2;

    return newLinkedList.next;
};
```