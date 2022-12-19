### 解题思路

这道题第一次看以为要构造双链表，然后用尾部逆向查找，但是显然达不到 只遍历一遍的要求。

细思：**删除第n个节点，只遍历一遍链表**

1. 将节点位置做标记 -- 我采用将节点放置到数组中，用数组下标标记
2. 删除节点实际就是，前一位的next 指向待删除节点的next，然后待删除节点next = null（否则会导致内存溢出，也就是这个节点并没有被删除）
3. 做一些特殊处理，比如删除的是头节点，尾节点
4. 返回 arr[0] (新head)

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    // 存储所有节点
    const arr = []
    while(head.next){
        arr.push(head)
        head = head.next
    }
    arr.push(head)
    const len = arr.length
    // 去掉头
    if(n === len){
        arr[0].next = null
        if(len === 1){
            arr[0] = null
        }else{
            // 返回新head
            arr[0] = arr[1]
        }
    }else if(n === 0){
        // 去掉尾
        arr[len - 2].next = null
    }else{
        arr[len - n -1].next = arr[len-n].next
        arr[len-n].next = null
    }

    // 返回头节点
    return arr[0]
};
```