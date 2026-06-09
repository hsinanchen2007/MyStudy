


![image.png](https://pic.leetcode-cn.com/d07a27fb9be2f909db71587736826862dea21604f6867060fed8b8cfb8ff7dd4-image.png)

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
var mergeKLists = function (lists) {
  let length = lists.length;
  if (length === 0) return null;
  if (length === 1) return lists[0];

  const merge = function (left, right) {
    if (left == right) return lists[left];
    let middle = (left + right) >> 1;
    let l = merge(left, middle);
    let r = merge(middle + 1, right);
    return mergeLists(l, r);
  }

  const mergeLists = function (list1, list2) {
    let dummyHead = new ListNode(0);
    let head = dummyHead;

    while (list1 && list2) {
      if (list1.val < list2.val) {
        head.next = list1;
        list1 = list1.next;
      } else {
        head.next = list2;
        list2 = list2.next;
      }
      head = head.next;
    }

    head.next = list1 ? list1 : list2;
    return dummyHead.next;
  }

  return merge(0, length - 1);
}
```