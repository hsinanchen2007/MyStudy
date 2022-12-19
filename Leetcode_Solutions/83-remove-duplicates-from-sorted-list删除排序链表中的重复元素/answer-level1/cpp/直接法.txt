思路：遍历链表，分别比较当前节点和下一个节点val是否相等。相等的话删除下一个节点，当前节点不变；不相等的话不删除下一个节点，下一个节点变为当前节点。直到碰到当前节点的next成员为NULL时跳出循环，返回链表。具体代码如下：
```
ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        ListNode* currentNode = head;
        ListNode* nextNode = NULL;
        while (currentNode->next != NULL)
        {
            nextNode = currentNode->next;
            if (currentNode->val == nextNode->val)
            {
                currentNode->next = nextNode->next;
            }
            else
            {
                currentNode = nextNode;
            }
        }
        return head;
    }
```
