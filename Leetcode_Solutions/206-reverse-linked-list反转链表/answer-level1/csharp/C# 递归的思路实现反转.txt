### 解题思路

##### 1. 题目概述：反转链表

##### 2. 思路：
   - 特征：单链表之间,是通过单个指针来建立联系的,目前就是要反转这种联系
   - 方案：递归的思路,只要下一个结点以后的结点都反转好了,那么让自己的下一个结点指向自己就 OK 了
   - 结果：传入新的头结点,让最后一个节点被它指向,然后递归方法返回的是当前节点的下一个节点,让这个节点指向自己即可

##### 3. 知识点：递归 单链表

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)

### 代码

```csharp []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
        public ListNode ReverseList(ListNode head)
        {
            var newHead = new ListNode(0);
            GetNextNode(newHead, head);

            return newHead.next;
        }

        private ListNode GetNextNode(ListNode newHead, ListNode nextNode)
        {
            if (nextNode == null || nextNode.next == null)
            {
                newHead.next = nextNode;
            }
            else
            {
                var nextTemp = GetNextNode(newHead, nextNode.next);
                nextTemp.next = nextNode;
                nextNode.next = null;
            }

            return nextNode;
        }
}
```