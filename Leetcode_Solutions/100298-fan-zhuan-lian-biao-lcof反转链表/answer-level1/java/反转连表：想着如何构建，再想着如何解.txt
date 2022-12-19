### 解题思路
此处撰写解题思路
1、想着如何构建简单的连表结构
2、从简单的构建，到循环构建
3、反解析
4、解决一些异常情况


简单构建：
ListNode node = new ListNode(1);
node.next = new ListNode(2);
node.next.next = new ListNode(3);

循环构建：

int i = 1;
ListNode p = new ListNode(i);
ListNode t = p;
while (true) {
    i++;
    t.next = new ListNode(i);
    t = t.next;
    if (i == 5) {
        break;
    }
}

反解析连表。

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
        if (null == head) {
            return null;
        }
        ListNode tmp = new ListNode(head.val);
        ListNode result = tmp;
        while (true) {
            head = head.next;
            if (null == head) {
                return result;
            }
            result = new ListNode(head.val);
            result.next = tmp;
            tmp = result;
        }
    }
}
```