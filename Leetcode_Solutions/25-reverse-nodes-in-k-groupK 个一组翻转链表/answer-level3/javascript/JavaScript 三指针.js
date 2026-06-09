```
function ListLength(l) {
    let p = l;
    let n = 0;
    while (p != null) {
        n++;
        p = p.next;
    }
    return n;
}
// 使用头插法将k个节点依次遍历
    var reverseKGroup = function(head, k) {
        let newhead = new ListNode(null);
        newhead.next = head; // 增加一个空的头节点
        let len = ListLength(newhead);
        let cur = newhead, // 当前遍历的节点
            pre = cur, // 本轮k个节点头插法插入的位置指针 
            s; // 获取删除的节点，将每次删除的节点s依次使用头插法插入pre指针之后
        let n = Math.floor((len - 1) / k); // 计算循环次数
        while (n--) {
            let i = k; // 记录k个 每k个节点为一次循环
            while (i--) {
                s = cur.next; // s指向遍历位置cur后的节点
                cur.next = cur.next.next; // 删除s节点
                s.next = pre.next; // 将s节点头插入pre指针后面
                pre.next = s;
                if (i == k - 1) // 如果是第一轮开始 cur后移一位
                    cur = cur.next;
            }
            pre = cur; // 每轮循环k个节点完毕 pre指向下一轮
        }
        return newhead.next;
    }; 
```
