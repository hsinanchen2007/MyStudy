#### 思路一：递归
```
var mergeTwoLists = function(l1, l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
};
```
#### 思路二
1. 新建链表`root`；
2. 遍历`l1、l2`，将值小的节点添加到`root`上；
```
var mergeTwoLists = function(l1, l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    let root = new ListNode(0);
    let pointer = root;
    while (l1 || l2) {
        let nextNode = new ListNode(Math.min(l1.val, l2.val));
        pointer.next = nextNode;
        pointer = pointer.next;
        if (!l1) {
            pointer.next = l2;
            return root.next;
        };
        if (!l2) {
            pointer.next = l1;
            return root.next;
        } 
    }
};
```

