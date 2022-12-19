```javascript
var reverseList = function(head) {
    // 递归解法
    if (head === null || head.next === null) {
        // 递归结束 返回尾节点
        return head;
    }
    // 保证返回的反转后的头
    let node = reverseList(head.next);
    // 改变指向
    head.next.next = head;
    // 照顾头节点
    head.next = null;
    return node

}
```
```javascript
var reverseList = function(head) {
    // 迭代解法
    let [pre, cur, nxt] = [null, head, head];
    while (cur) {
        nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt; 
    }
    return pre;

};
```