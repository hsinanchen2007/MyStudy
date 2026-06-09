### 解题思路
删除当前结点有两种方式，一种是前驱结点直接指向当前结点的后继结点；一种是后继结点直接覆盖当前结点；在本题目中传入当前结点，我们只能得到它的后继结点信息，所以使用第二种方法解题；
![237删除链表中的结点.png](https://pic.leetcode-cn.com/2d53e8d0663ec82fd74384d5c45b3c002f4d4d4751f1e51a462253b5749c9315-237%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E7%BB%93%E7%82%B9.png)

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
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```