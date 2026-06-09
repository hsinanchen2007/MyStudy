### 解题思路
主要是指针操作和链表概念。题很简单我很笨。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *lr;
        int c = 0;
        while(l1 != NULL && l2 != NULL){
            int tmp = l1->val + l2->val + c;
            c = tmp / 10;
            ListNode *t = new ListNode(tmp % 10);
            if(res == NULL){
                res = t;
                lr = res;
            }
            else{
                lr->next = t;
                lr = lr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != NULL){
            lr->next = l1;
            while(c){
                if(lr->next == NULL){
                    ListNode *t = new ListNode(c);
                    lr->next = t;
                    c = 0;
                }
                else{
                    lr = lr->next;
                    int temp = lr->val + c;
                    lr->val = temp % 10;
                    c = temp / 10;
                }
            }
        }
        if(l2 != NULL){
            lr->next = l2;
            while(c){
                if(lr->next == NULL){
                    ListNode *t = new ListNode(c);
                    lr->next = t;
                    c = 0;
                }
                else{
                    lr = lr->next;
                    int temp = lr->val + c;
                    lr->val = temp % 10;
                    c = temp / 10;
                }
            }
        }
        if(c){
            ListNode *t = new ListNode(c);
            lr->next = t;
        }
        return res;
    }
};
```