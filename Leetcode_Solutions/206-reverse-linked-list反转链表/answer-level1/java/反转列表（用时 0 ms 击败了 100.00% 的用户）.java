### 解题思路
![image.png](https://pic.leetcode-cn.com/71cd664e7e2b40eae32c30b15f2c1d287ee5c53bf5529e6fbfba517282b8b577-image.png)

> 方法很简单 ：
> 1. 记录下当前节点的下一个，
> 2. 将当前节点的下一个指针指向当前接点的前一个，
> 3. 将当前节点下移循环，直到当前节点为空
> 4. 返回当前节点的前一个节点就可以了

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
      ListNode pre = null;
      ListNode cur = head;

      while (cur != null) {
        ListNode temp = cur.next;
        cur.next = pre;//前节点指向下一个节点
        pre = cur;    //前指针后移
        cur = temp;// 当前指针后移
      }
      return pre;
    }
}
```