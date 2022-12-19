这个题用的双指针，一直在考虑怎样让指针一次走两步而不报错，不出现null.next的情况，写了个自认为对的思路，结果超出时间限制，希望大神们看到我的这个题解，可以为我解答这个为什么不能break出去，会超出时间限制。
```
var swapPairs = function(head) {
    if(!head) return null;
    let dummy = new ListNode(0);
    // 双指针
    let slow = head;
    let fast = head.next;
    // 前指针
    let prev = dummy;
    while(slow) {
        // 交换操作
        slow.next = fast.next;
        fast.next = slow;
        prev.next = fast;
        prev = slow;
        // 进行第一次指针后移操作，不会报错
        fast = slow;
        slow = slow.next;
        // 第二次后移操作前先判断是否已到链表尾部
        if(slow && slow.next) {
            fast = slow;
            slow = slow.next;           
        } else {
            break;
        }
        // 每次都交换快慢指针
        let temp = slow;
        slow = fast;
        fast = slow;       
    }
    return dummy.next;
};
```

没想到还能这样做，如此犀利，膜拜大神，原作在这里：[三元神的博客](http://47.98.159.95/leetcode-js/linkedlist/001.html#no-3-%E4%B8%A4%E4%B8%AA%E4%B8%80%E7%BB%84%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8)
```
var swapPairs = function(head) {
    if(head == null || head.next == null) 
        return head;
    let dummyHead = p = new ListNode();
    let node1, node2;
    dummyHead.next = head;
    // 直接把赋值和判断融为一体，若已到队尾就会报错，然后跳出循环
    // 这个思想太厉害了！！！
    while((node1 = p.next) && (node2 = p.next.next)) {
        node1.next = node2.next;
        node2.next = node1;
        p.next = node2;
        p = node1;
    }
    return dummyHead.next;
};
```
