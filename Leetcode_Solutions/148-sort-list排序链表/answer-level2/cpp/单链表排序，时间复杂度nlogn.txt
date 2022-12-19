### 解题思路
1. 快慢指针分割链表，快指针走2步，慢指针走1步
循环终止条件：fast->next==NULL
```
fast=head;
slow=head;
while(fast->next)
{
    fast=fast->next;
    if(fast->next){
        fast=fast->next;
        slow=slow->next;
    }else{
        break;
    }
}
```
2. 此时的slow指针位置：若单链表长度为odd，slow位于中间。若单链表长度为even，slow位于左半部分，最后一个位置。
可以简单画个图移动一下指针就明白了。
3. 递归链表
```
tmp = slow->next; //保存右半部分链表
slow->next=NULL; //割断链表
left=sort(head);
right=sort(tmp);
```
4. 合并链表
left和right均为有序链表头指针，合并2链表算法如下
```
while(left&&right){
    if(left->val>right->val){
        L->next=right;
        right=right->next;
    }else{
        L->next=left;
        left=left->next;
    }
    L=L->next;
}
last = left?left:right;
while(last){
        L->next=last;
        last=last->next;
        L=L->next;
    }
```

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
        if(head&&head->next==NULL)
        {
            return head;
        }
        if(!head){
            return head;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next){
            fast=fast->next;
            if(fast->next)
            {
                fast=fast->next;
                slow=slow->next;
            }else{
                break;
            }
        }
        ListNode *tmp=slow->next;
        slow->next=NULL;
        ListNode *left=sortList(head);
        ListNode *right=sortList(tmp);
        ListNode LL;
        ListNode *L = &LL;
        ListNode *New_Head = L;
        while(left&&right){
            if(left->val>right->val)
            {
                L->next=right;
                right=right->next;
            }else{
                L->next=left;
                left=left->next;
            }
            L=L->next;
        }
        ListNode *tmp2 = left?left:right;
        while(tmp2){
            L->next = tmp2;
            L=L->next;
            tmp2=tmp2->next;
        }
        return New_Head->next;
    }
};
```