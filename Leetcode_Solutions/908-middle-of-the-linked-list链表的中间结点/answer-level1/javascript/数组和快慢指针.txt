1.使用数组保存链表的顺序和索引,不过速度比较慢
2.使用快慢指针,如果链表长度是偶数,比如[1,2,3,4],快指针走1,慢指针走1,2,快指针到2,慢指针到3,4,快指针到3,慢指针为空,输出慢指针(当前3);
如果是奇数长度,如[1,2,3],快1->慢1,慢2.快2->慢3,慢4. 慢4为空,所以返回快指针(当前是2)

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    let fast = head,
        slow = head;
    while(slow && fast) {
        let i = 2;
        while(i-- && fast) {
            if(slow === head) i--;
            fast = fast.next;
        }
        if(!fast) return slow;
        slow = slow.next;
    }
    return slow;
    
    /*let i = 0,
        n = head,
        vas = [];
    while(n) {
        vas[i++] = n;
        n = n.next;
    }
    if(i & 1) {
        return vas[(i + 1)/2 - 1];
    } else {
        return vas[i/2];
    }*/
};
```