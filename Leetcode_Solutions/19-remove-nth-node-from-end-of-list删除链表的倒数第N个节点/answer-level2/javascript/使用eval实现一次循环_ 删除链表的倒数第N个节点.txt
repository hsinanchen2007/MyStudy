
```
var removeNthFromEnd = function(head, n) {
    var c = head, l = 0;
    while (c) { // 计算链表length
        l++;
        c = c.next;
    }
    // 通过 l和n 来获取需要跳过的节点， 用eval执行多个next跳过。完成一次循环
    eval(`head${'["next"]'.repeat(l - n)}=head${'["next"]'.repeat(l - n + 1)}`)
    return head;
};
```
