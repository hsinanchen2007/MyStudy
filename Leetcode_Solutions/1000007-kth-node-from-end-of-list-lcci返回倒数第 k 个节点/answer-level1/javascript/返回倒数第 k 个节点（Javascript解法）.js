### 解题思路
建立临时数组，循环反向追加，直到head指向null为止，提取数组第2位【k-1】则是需要的结果

##### 小BUG 
输入 [1]，2
输出 ???
期望结果 -1

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
 * @param {number} k
 * @return {number}
 */
var kthToLast = function(head, k) {
    let list = []
    while(head){
        list.unshift(head.val)
        head = head.next
    }
   return (r = list[k - 1]) ? r : null
};
```