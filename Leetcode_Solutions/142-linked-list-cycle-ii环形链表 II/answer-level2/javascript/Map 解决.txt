将每次遍历过的 node 都通过 map 存储起来，如果出现当前遍历的 node 已经出现在 map 中了，说明有环，直接返回 node 即可，反之最后返回 null

```javascript
var detectCycle = function(head) {
    var map = new Map();
    var result = null;
    while (head !== null) {
        if (!map.has(head)) {
            map.set(head);
        } else {
            return head;
        }
        head = head.next;
    }
    return result;
};
```