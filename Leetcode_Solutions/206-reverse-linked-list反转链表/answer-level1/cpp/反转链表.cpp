### 解题思路
此处撰写解题思路

### 代码
就改了一句话差别这么大……就删了p=p->next改了p的初始化
```cpp
class Solution {//**这个要8ms**
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;//对于传入的结点指针，必须有判空操作！！！
        ListNode*p=head;
        ListNode*q=p;
        p=p->next;
        while(p){
            q->next=p->next;
            p->next=head;
            head=p;
            
            p=q->next;
        }
        return head;
    }
};
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;//对于传入的结点指针，必须有判空操作！！
        ListNode*p=head->next;//**改了p的初始化，直接变成0ms……**
        ListNode*q=head;
        while(p){
            q->next=p->next;
            p->next=head;
            head=p;
            
            p=q->next;
        }
        return head;
    }
};

