### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户 内存消耗 :5.5 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode * p = head;
    struct ListNode * tmp;

    struct ListNode * result;
    if(head == NULL || head->next == NULL){
        return head;
    }

    result = head->next;

    while(p && p->next){
        tmp = p->next->next;
        p->next->next = p;
        if(tmp != 0){
            if(tmp->next != 0){
                p->next = tmp->next;
            }
            else{
                p->next =  tmp;
            }            
        }
        else{
            p->next = NULL;
        }
        p = tmp;
    }

    return result;
}
```