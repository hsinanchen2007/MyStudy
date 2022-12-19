解决思路：
head用于移动到当前节点，所以一开始要把链表的头保存下来；
如果下一个节点的值和当前节点值相等，就将当前节点指向下下个节点(十分巧妙的运用链表的特性来“删除”元素)；
比较完之后，将head移动到下一个节点；

```
var deleteDuplicates = function(head) {
    let saveHead = head
    // 外层while控制循环完整个链表的长度
    while(head && head.next) {
        // 内层循环用于比较当前值是否和下一个值相等，相等则通过改变节点的指向来“删除”元素
        while(head.next && head.next.val === head.val) {
            head.next = head.next.next
        }
        // 移动head到下一个节点
        head = head.next
    }
    return saveHead
};
```
