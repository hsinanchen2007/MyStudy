### 解题思路
此处撰写解题思路

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode *new_head=NULL;
        while(head!=NULL)
        {
            //原地翻转一次
            ListNode *next_head=head->next;
            head->next=new_head;
            new_head=head;
            head=next_head;
        }
        //现在new_head为新的头结点，倒数第n个结点及新链表顺数第n个结点了
        
        ListNode *res_newhead=NULL;

        if(n==1)
        {
            new_head=new_head->next;   //头结点往后移动一位
            while(new_head!=NULL)
            {
                ListNode *next_head=new_head->next;
                new_head->next=res_newhead;
                res_newhead=new_head;
                new_head=next_head;
            }
            return res_newhead;
        }
            
        while(new_head!=NULL)
        {
            n--;
            ListNode *next_head=new_head->next;
            if((n==1)&&(next_head!=NULL))
            {
                next_head=next_head->next;
            }
            new_head->next=res_newhead;
            res_newhead=new_head;
            new_head=next_head;
        }
        return res_newhead;
    }
};
```感觉代码可改进，有冗余