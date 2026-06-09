**思路：** 双指针，一个指向不重复的最后一节点，一个负责遍历。要注意遍历结束后，将第一个指针的下一个节点设为null。
```
public ListNode DeleteDuplicates(ListNode head)
        {
            if (head == null || head.next == null)
            {
                return head;
            }

            ListNode currentNode = head;
            ListNode loopNode = head.next;

            while (loopNode != null)
            {
                if (loopNode.val != currentNode.val)
                {
                    currentNode.next = loopNode;
                    currentNode = loopNode;
                }

                loopNode = loopNode.next;
            }
            currentNode.next = null;

            return head;
        }
```
**注：** 代码写完后还是要多多用例子去检验自己的代码