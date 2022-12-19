### 解题思路

##### 1. 题目概述：反转单链表

##### 2. 思路：
   - 特征：因为单链表是单项的,一旦连接关系断掉,后面就会消失了,所以在断掉前,要把下一个结点记录下来
   - 方案：考虑使用循环的方式 分别用 2 个变量记录 当前节点,下一个节点 每次先记录好下一个节点,然后让头节点指向当前节点
   - 结果：循环过 n 个结点以后,得到的就是所需的解

##### 3. 知识点：循环 单链表

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


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

            var curNode = head;
            while (curNode != null)
            {
                var nextNode = curNode.next;

                curNode.next = newHead.next;
                newHead.next = curNode;

                curNode = nextNode;
            }

            return newHead.next;
        }
}
```