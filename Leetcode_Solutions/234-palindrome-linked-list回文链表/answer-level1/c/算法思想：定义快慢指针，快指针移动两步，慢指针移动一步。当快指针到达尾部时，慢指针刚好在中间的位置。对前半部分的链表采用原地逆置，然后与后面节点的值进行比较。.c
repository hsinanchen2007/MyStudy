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
bool isPalindrome(struct ListNode* head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    if(head->next->next==NULL){
        if(head->val == head->next->val){
            return true;
        }
        else
            return false;
    }

    struct ListNode *fast,*slow;
    slow = head->next;
    fast = head->next->next;

//      采用快慢指针寻找中间的位置
    while(fast && fast->next!=NULL){
        fast=fast->next->next;
        slow = slow->next;
    }    

//      对前半部分链表采用原地逆置的算法
    struct ListNode *pre,*r;
    pre = r = NULL;
    while(head!=slow){
        r = head->next;
        head->next = pre;
        pre = head;
        head = r;
    }

//      若链表为奇数个节点，则不用比较中间节点
    if(fast!=NULL && fast->next==NULL){
        slow = slow->next;
    }

//      比较前后两部分节点的值
    while(pre!=NULL){
        if(pre->val != slow->val){
            return false;
        }
        pre=pre->next;
        slow=slow->next;
    }    
    return true;
}
```