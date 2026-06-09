### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//迭代法
struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL)
      return NULL;
    struct ListNode *h1,*h2,*h3;
    h1=NULL;
    h2=head;
    h3=head->next;
    while(h2!=NULL)
    {
        h2->next=h1;
        h1=h2;
        if(h3 == NULL)  //防止后面h2==NULL时，h3会越界
        {
            break;
        }
        h2=h3;
        
        h3=h2->next;
    }
    return h2;
}


```