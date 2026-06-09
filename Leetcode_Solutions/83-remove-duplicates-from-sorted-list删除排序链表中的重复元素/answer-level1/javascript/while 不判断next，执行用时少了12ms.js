### 解题思路
此处撰写解题思路

### 代码
* 这是第一版代码，在while里面既判断了cur 和 cur.next 
![a.png](https://pic.leetcode-cn.com/369a0e576fb833e2a13b16227878fea580ca1f0b79b80f9b46dd2a01c7b679a2-a.png)

```
var deleteDuplicates = function(head) {
    if (head === null) return head
    let cur = head
    while(cur && cur.next) {
        if (cur.next.val === cur.val) {
            cur.next = cur.next.next || null
        } else {
            cur = cur.next
        }
        
    }
    return head
};
```
* 第二版 while仅判断cur，将对cur.next的判断移到if里面，且去除了`cur.next.next || null `，这个null的存在没啥意义干掉了
![b.png](https://pic.leetcode-cn.com/de39ecd181460b980465a95566f170d26df92f8c53ee28164a2d34ac10f83cc2-b.png)
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
var deleteDuplicates = function(head) {
    if (head === null) return head
    let cur = head
    while(cur) {
        if (cur.next && cur.next.val === cur.val) {
            cur.next = cur.next.next
        } else {
            cur = cur.next
        }
        
    }
    return head
};
```