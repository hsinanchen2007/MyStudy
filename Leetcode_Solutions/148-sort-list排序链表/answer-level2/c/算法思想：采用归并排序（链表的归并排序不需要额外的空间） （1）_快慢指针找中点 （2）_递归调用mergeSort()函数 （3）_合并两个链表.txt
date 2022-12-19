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
struct ListNode* merge(struct ListNode* left,struct ListNode* right){
    struct ListNode head;   //头结点
    struct ListNode *current = &head;
//      归并排序
    while(left && right){
        if(left->val > right->val){
            current->next = right;
            right = right->next;
        }
        else{
            current->next = left;
            left = left->next;
        }
        current = current->next;
    }
 //     最后还会剩下一段链表，只会执行一个   
    if(left){
        current->next = left;
    }
    if(right){
        current->next = right;
    }
    return head.next;
}

struct ListNode* sortList(struct ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
//      用快慢指针找中点
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }    
    fast = slow->next;
    slow->next = NULL;
    return merge(sortList(head),sortList(fast));
}
```