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
//  反转链表
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p,*r=NULL;  //p为工作指针，r为p的后继，防止断链
    p=head;
    while(p){ //  依次将元素节点摘下
        head = head->next;
        p->next = r;
        r = p;
        p = head;
    }
    return r;
}

void reorderList(struct ListNode* head){
    if(head==NULL || head->next==NULL){
        return;
    }

//  设置快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;

//      找中间节点
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* end = reverseList(slow->next);
    slow->next = NULL;
    struct ListNode* current = head;
    while(end){
        //创建头结点
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = end->val;
        node->next = current->next;
        current->next = node;
        current = current->next->next;
        end = end->next;
    }

}
```