### 解题思路
利用归并排序
1.我们定义三个节点，然后通过一次遍历找到链表的中间节点。注意偶数长度的链表和奇数长度的链表。
2.在中间节点处断开链表，即操作是pre->next = NULL
3.调用merge合并两个有序链表即可。

### 代码

```cpp
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;

        while (fast && fast->next) 
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //退出循环的时候, fast-->next == NULL即fast在倒数第一个节点 pre在中点
        pre->next = NULL;//断开节点的操作

        return merge(sortList(head), sortList(slow));
    }

    //归并即合并两个有序链表
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val > head2->val)
            {
                cur->next = head2;
                head2 =  head2->next;
            }
            else
            {
                cur->next = head1;
                head1 = head1->next;
            }
            cur = cur->next;
        }
        if(head1 == NULL)
        {
            cur->next = head2;
        }
        if(head2 == NULL)
        {
             cur->next = head1;
        }
        return dummyHead->next;
    }
    
};
```