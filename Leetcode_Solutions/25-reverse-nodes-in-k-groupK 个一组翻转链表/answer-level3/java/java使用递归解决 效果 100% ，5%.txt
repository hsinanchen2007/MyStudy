### 解题思路
思路：递归方法
这题与24题类似；每 k 个节点一组进行翻转，即 先将K个节点翻转之后，返回结果的first节点，然后 上一层方法中翻转结果中的最后一个节点（也就是翻转前的第一个节点）.next 赋值即可。
具体看代码注释。。。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        //特殊判断
        if (k == 1) {
            return head;
        }
        //这里是为了校验，若当前链表长度 < k 则不翻转。
        ListNode validNode = head;
        for (int i = 0; i < k; i++) {
            if (validNode == null) {
                return head;
            }
            validNode = validNode.next;
        }
        //这里是 执行这段链表的翻转操作
        int num = k - 1;
        ListNode preNode = head;
        ListNode currentNode = preNode.next;
        preNode.next = null;
        ListNode nextNode = null;
        while (currentNode != null && num > 0) {
            nextNode = currentNode.next;
            currentNode.next = preNode;

            preNode = currentNode;
            currentNode = nextNode;
            num--;
        }
        //获取 下一段链表翻转结果的first节点
        ListNode realNextNode = reverseKGroup(nextNode, k);
        //将两段链表连接
        head.next = realNextNode;
        //返回此段链表翻转结果的first节点
        return preNode;
    }
}
```