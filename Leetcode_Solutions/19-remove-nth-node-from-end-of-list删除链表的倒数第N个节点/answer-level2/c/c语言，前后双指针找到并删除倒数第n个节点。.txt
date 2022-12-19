### 解题思路
保持前后两指针的n-1间距到链表结尾，找到并删除指针节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(head->next==NULL) return NULL; 
    struct ListNode *front = head;              //前指针
    struct ListNode *tail = head;               //后指针

    //前指针前进n-1步，保持head节点是相对front的倒数第n节点
    for(int i=0; i<n-1; i++)   
        front = front->next;

    //如果front节点已经是倒数第1节点，去掉头结点（特殊情况，需要删除头结点）
    if(front->next==NULL) return head->next;   

    //前后指针指向的节点距+1，通过指向需要删除节点的前一节点，将该节点删除
    front = front->next;                        
    while(front->next)                          
    {
        front = front->next;
        tail = tail->next;
    }
    tail->next = tail->next->next;              //删除该节点

    return head;
}
```