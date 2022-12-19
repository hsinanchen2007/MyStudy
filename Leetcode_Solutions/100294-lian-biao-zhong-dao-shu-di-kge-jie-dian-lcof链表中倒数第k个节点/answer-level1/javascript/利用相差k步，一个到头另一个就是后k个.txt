### 解题思路
var getKthFromEnd = function(head, k) {
    if(head === null || k<0){
        return null
    }
    var fast = head; // 开始将head分别给fast 和slow
    var slow = head;
    while(k--){
        fast = fast.next  // fast先走k步，之后一起走，这样保证fast和slow相差k步
    }
    while(fast){   // 当fast走到头到时候，slow正好和他相差k步，所以slow就是从此到尾部的链表
        fast = fast.next;
        slow = slow.next;
    }
    return slow
};
```