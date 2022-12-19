## 第一版，在短链表的尾部添加值为0的节点
> 136ms,38.7MB。
```javascript []
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
  if (!(l1 && l2)) return l1 || l2;

  let add1 = 0;
  let res = l1;
  while (l1 || l2) {
    if (!l1.next && l2.next) l1.next = new ListNode(0);
    else if(l1.next && !l2.next) l2.next = new ListNode(0);

    const curSum = l1.val + l2.val + add1;
    add1 = curSum >= 10 ? 1 : 0;
    l1.val = curSum % 10;

    if (add1 && !l1.next && !l2.next) {
      l1.next = new ListNode(1);
      break;
    }

    l1 = l1.next;
    l2 = l2.next;
  }
  return res;
};
```
### 思路
1. 同时遍历两个链表，将两个链表对应节点值的和放到`l1`的该节点中，最后可以直接返回`l1`，减少新建链表消耗的空间
2. 若两链表长度相同，则很nice，判断下最后是否需要多进一位1就好，然后结束，返回`l1`
3. 若两链表长度不同：
    + 若最后一对节点（以短链表最后节点为终点）的和无需进一时：如果`l1`是短的那个，则将`l2`比`l1`长的部分拼接到`l1`后面；如果`l1`是长的那个则无需拼接。然后结束，直接返回`l1`
    + 若最后一对节点的和需要进一时，则在短的那个链表尾部添加一个值为0的节点，然后重复2、3步直到结束

##### ps:这道题有这么多人写题解的原因是这道题的题号是2？
