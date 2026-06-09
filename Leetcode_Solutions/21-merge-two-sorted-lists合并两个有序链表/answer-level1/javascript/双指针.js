## 第一版，双指针
> 88ms,35.6M。
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
var mergeTwoLists = function(l1, l2) {
  if (!(l1 && l2)) return l1 || l2;
  if (l1.val > l2.val) [l1, l2] = [l2, l1];
  for (let cur1 = l1, cur2 = l2; cur1 && cur2; cur1 = cur1.next) {
    if (cur1.val <= cur2.val) { // 这一行的if不要也可以
      if (!cur1.next) {
        cur1.next = cur2;
        return l1;
      }
      if (cur1.next.val <= cur2.val) continue;
      let cur1Temp = cur1.next;
      cur1.next = null;

      let cur2Temp = cur2.next;
      cur2.next = null; // 将cur2从l2中分割出来

      cur1.next = cur2; // 将插入l1对应位置
      cur1.next.next = cur1Temp;

      cur2 = cur2Temp; // 将l2的下一个节点设为cur2
    }
  }
  return l1;
};
```
## 思路：
1. l1与l2有一个为空时直接返回不为空的那个
2. 将头节点val值小的那个链设为l1
3. 以l1为基础遍历，遍历过程中cur1为l1的第n个节点，cur2为l2的第n个节点，每次将cur1指向的位置往后移一个节点
4. 当cur2.val >= cur1.val && cur2.val < cur.next.val时，则将cur2从l2中分割出来插入l1中cur1后面的位置，并将cur2指向的位置向后移一个节点
5. 如果cur2已经指向最后一个位置则结束循环，或者l1指向最后一个位置但l2还未到最后则将l2剩下的部分直接补到l1后面
6. 最后返回l1

---
### to do 暂时还没看题解，先想下递归怎么做