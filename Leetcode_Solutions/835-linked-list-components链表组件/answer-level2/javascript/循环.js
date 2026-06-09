### 解题思路
首先，以不变应万变；
有一个链表，顺序固定；有一个参数去判断当前是否是连接状态；然后遍历他，如果存在在G数组里面，如果存在，判断是否是链接状态，如果不是链接，就代表着一个新的组件在存在，如果是链接，则表示上一个组件还没有结束，如果不存在，就将连接断开
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
 * @param {number[]} G
 * @return {number}
 */
var numComponents = function(head, G) {
    link= false;
    all = 0;
    while(head != null){
        if (G.includes(head.val)){
            if(!link){
                link = true;
                all++;
            }
        }else {
            link = false;
        }
        head = head.next;
    }
    return all;
};
```