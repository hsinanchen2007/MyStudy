### javascript数组方法

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
    // 数组中是否包含某元素可以用 indexOf方法，若包含则返回对应索引值，不包含返回0
    var arr = [];
    var curr = head;
    var bol = true;
    while(curr != null) {
        if(arr.indexOf(curr) != -1) {            
            return bol;
        }
        
        arr.push(curr);
        curr = curr.next;
    }
    return !bol;
};
```
### 大神的作品：用set代替数组
```
var hasCycle = function (head) {
    let set = new Set()
    while (head != null) {
        if (set.has(head)) {
            return true
        } else {
            set.add(head)
        }
        head = head.next
    }
    return false
};
```
