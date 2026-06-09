### 解题思路
提交出错n次 因为没用自己编译器
始终不知道l1 l2为空时候的判断条件 后来发现是null

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
    // if(l1||l2)
    if (l1 == null) {
        return l2;
    }
    if (l2 == null) {
        return l1;
    }
    let newArr = [...toArr(l1).concat(toArr(l2))].sort((a,b)=>{return a-b});
    let res = toList(newArr);
    return res;
};
function toArr(list) {
    let arr = [];
    while (list) {
        arr.push(list.val);
        list = list.next;
    }
    return arr;
}
function toList(arr) {
    let obj = new ListNode(arr.shift());
    let str = obj;
    while (arr.length) {
        str.next = new ListNode(arr.shift());
        str = str.next
    }
    return obj;
}
```