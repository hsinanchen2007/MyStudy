### 解题思路
依次遍历全部链表，将链表中的全部元素保存在数组当中并进行排序，根据数组生成新的链表并返回。

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
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    const temp = [];
    if(lists.length === 0) return null;
    for(let i = 0;i < lists.length;i ++) {
        while(lists[i]) {
            temp.push(lists[i].val);
            lists[i] = lists[i].next;
        }
    }
    if(temp.length === 0) return null; // 校验全为空数组边界条件
    temp.sort((a,b) => a - b);
    const head = new ListNode(temp[0]);
    let res = head;
    for(let i = 1;i < temp.length;i ++) {
        res = res.next = new ListNode(temp[i]);
    }
    return head;
};
```