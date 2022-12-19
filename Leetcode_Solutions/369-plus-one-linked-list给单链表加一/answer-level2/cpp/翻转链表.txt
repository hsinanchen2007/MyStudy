### 解题思路
翻转链表 优先加1 大于9就循环

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
    ListNode* plusOne(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode* re = reverse(head);
        ListNode *c = re->next,*t = re;
        t->val += 1;
        while(c != NULL && t->val > 9){
            t->val -= 10;
            c->val += 1;
            t = c;
            c = c->next;
        }

        if (t->val > 9) {
            t->val -= 10;
            t->next = new ListNode(1);
        }
        
        
        return reverse(re);
    }

    ListNode* reverse(ListNode* head){
        ListNode *cur = head->next,*pre = head,*tmp = NULL;
        pre->next = NULL;
        while(cur != NULL){
            tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;          
        }
        return pre;
    }
};
```