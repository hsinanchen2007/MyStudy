### 解题思路
哈希表，简单明了，就是有点浪费空间了，其实这道题可以原地操作的。
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
var deleteDuplicates = function(head) {
    if(head == null){
        return head
    }
    let map = new Map();
    let now = head;
    while(now != null){
        let count = map.get(now.val);
        if(count){
            map.set(now.val, count+1);
        }else{
            map.set(now.val, 1);
        }
        now = now.next;
    }
    let newHead = new ListNode(null);
    let newNow = newHead;
    map.forEach((val,key) => {
        if(val != 1){
            map.delete(key);
        }
    })
    let i = 0;
    if(map.size <= 0){
        return null;
    }
    map.forEach((val,key)=>{
        i++;
        newNow.val = key;
        if( i < map.size){
            newNow.next = new ListNode(null);
            newNow = newNow.next
        }
    })
    return newHead;
};
```