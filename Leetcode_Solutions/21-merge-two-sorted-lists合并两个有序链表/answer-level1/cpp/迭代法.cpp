### 解题思路
简单的迭代过程，先定义一个节点head，比较两链表头结点大小并赋值给head完成其初始化，将head保存为head0.接下来的步骤是逐次比较两链表元素的大小并将小的元素连接到head0为首的链表上。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1  )return l2;
        if(!l2  )return l1;
        ListNode* head;
        if(l1 -> val <= l2 -> val ) 
        {
            head=l1;
            l1 = l1 -> next;
        }
        else  
        {
            head=l2;
            l2 = l2 -> next;
        }
        ListNode* head0 = head;
        while(l1 && l2)
        {
            if(l1 -> val < l2 -> val ) 
            {
                head -> next =l1;
                l1 = l1 -> next;
            }
            else 
            {
                head -> next =l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        while(l1)
        {
            head -> next =l1;
            l1 = l1 -> next;
            head = head -> next;
        }
        while(l2)
        {
            head -> next =l2;
            l2 = l2 -> next;
            head = head -> next;
        }
        return head0;
    }
};
```