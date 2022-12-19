#### 解题思路:
删除链表的倒数第N个结点，即删除反转后的链表的正数第N个结点。因此，可通过如下步骤解决此题：
- 对链表进行原地反转；
- 删除反转后的链表的正数第N个结点；
- 对删除结点后的链表再次反转，复原成原来的状态。
#### 代码如下:
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nodeTmp = NULL;

        while(curr != NULL)
        {
            nodeTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nodeTmp;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the linked list
        ListNode* reverseListHead = reverseLinkedList(head);

        ListNode* sentinel = new ListNode(-1);
        sentinel->next = reverseListHead;

        ListNode* prev = sentinel;
        ListNode* curr = reverseListHead;

        for(int i = 1; i < n; i++)
        {
            prev = prev->next;
            curr = curr->next;
        }
        ListNode* toDelete = curr;
        prev->next = curr->next;
        toDelete->next = NULL;

        delete toDelete;
        ListNode* newHead = sentinel->next;
        delete sentinel;

        return reverseLinkedList(newHead);
    }
};
```
链表反转我们使用的是基于迭代的原地反转，时间复杂度为O(N)，空间复杂度为O(1)。删除结点时，我们使用了prev指针和curr指针遍历链表，当curr到达要删除的结点时，让prev->next=curr->next，时间复杂度最差为O(N)，空间复杂度为O(1)。本方法进行了两次链表反转，一次结点删除，所以其复杂度分析如下：
#### 时间复杂度：O(N)
#### 空间复杂度：O(1)