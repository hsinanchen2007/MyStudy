**思路：** 哨兵节点的方法（很多链表题目都是这个思路），要特别注意如果最后一个节点也是目标值节点的情况
```
public ListNode RemoveElements(ListNode head, int val)
        {
            ListNode newHead = new ListNode(0);
            ListNode previousNode = newHead;
            ListNode currentNode = head;

            while (currentNode != null)
            {
                if (currentNode.val != val)
                {
                    previousNode.next = currentNode;
                    previousNode = currentNode;
                }
                currentNode = currentNode.next;
            }
            //特别注意不能少了这行
            currentNode.next = null;

            return newHead.next;
        }
```

![image.png](https://pic.leetcode-cn.com/9c04ea37e0811330601b553812c3b0069b3ac5be1d4d73225d4e3680b1ceab72-image.png)
