### 解题思路
定义一个值add，判断两个链表的值相加是否超过10，超过则往后进1
两个链表的val相加，并加上add，计算下一次的add，以及相加后的个位数
将得到的个位数塞进保存结果的链表
注意最后相加时，是否有进1

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
var addTwoNumbers = function(l1, l2) {
    function ListNode(val) {
      this.val = val;
      this.next = null;
    }
    let result, temp;
    let add = 0;
    const getVal = (l) => l ? l.val : 0;
    const getNext = (l) => l ? l.next : l;
    while (l1 || l2) {
        let now = getVal(l1) + getVal(l2) + add;
        add = now >= 10 ? 1 : 0;
        now = now >= 10 ? now - 10 : now;

        if (!result) {
            result = new ListNode(now);
            temp = result;
        } else {
            temp.next = new ListNode(now);
            temp = temp.next;
        }
        l1 = getNext(l1);
        l2 = getNext(l2);
    }
    if (add) temp.next = new ListNode(add);
    return result;
};
```