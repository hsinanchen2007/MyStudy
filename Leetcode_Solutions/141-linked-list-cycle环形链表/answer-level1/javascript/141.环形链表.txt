### 解题思路
方法一、哈希Map
将链表的每一个节点通过map.set(key,value)方法加入到map表中，当把所有的节点全部都加进去之后，
如果有环，通过map.has(key)方法判断下一个节点是否已经存在在表中，如果已经存在说明有环，返回true，否则返回false

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
 * @return {boolean}
 */
var hasCycle = function(head) {
    var map = new Map();
    while(head!=null){
        if(map.has(head)){
            return true;
        }else{
            map.set(head,2);//不加这句会超出时间限制，应该就是把每一个节点的值在map表中新建一个键值
            head=head.next;
        }
    }
    return false;
};
```
方法二、想象环形跑圈，同时起步，跑得快的经过多次循环一定可以追上跑得慢的
假设有两个指针，跑得快的一次两步，跑得慢的一次一步，假设存在环，则最终二者会相遇
```
var hasCycle = function(head) {
    var fast=slow=head;
    while(fast&&fast.next){
        fast=fast.next.next;
        slow=slow.next;
        if(fast==slow){
            return true;
        }
    }
    return false;
};
```
