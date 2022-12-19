### 解题思路
简单的循环解法

### 代码

```javascript
var deleteNode = function (head, val) {
    // 头结点保存指针
    let preHead = new ListNode();
    preHead.next = head;
    
    // head为空或head仅有一个节点
    if (!head || !head.next) return head

    while (head.val != val) {
        head = head.next;
    }

    // 发现节点且节点不处于链表尾部，O(1) 替换删除
    if (head.next !== null) {
        head.val = head.next.val;
        head.next = head.next.next;
    } else {
        // 问题转化成：删除链表尾结点，从头遍历删除即可
        let copy = preHead.next;
        while (copy.next.next) {
            copy = copy.next;
        }
        copy.next = null;
    }
    return preHead.next
};
```