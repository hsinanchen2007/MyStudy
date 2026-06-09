### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummy = new ListNode(0);
    ListNode tail = dummy;

    int carry = 0;

    while (l1 != null || l2 != null || carry != 0) {
      int tmpVal = carry;

      if (l1 != null) {
        tmpVal += l1.val;
        l1 = l1.next;
      }

      if (l2 != null) {
        tmpVal += l2.val;
        l2 = l2.next;
      }

      ListNode nextNode = new ListNode(tmpVal % 10);
      carry = tmpVal / 10;

      tail.next = nextNode;
      tail = nextNode;
    }

    return dummy.next;
  }
}
```