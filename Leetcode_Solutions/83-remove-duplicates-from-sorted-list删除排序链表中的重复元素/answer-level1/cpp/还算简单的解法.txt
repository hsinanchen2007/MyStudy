### 解题思路
# 借鉴一下还是可以的  写的不好的见谅 代码简单 看一下就懂
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* w1 = head;
        if(w1 == NULL)
        {
            return head;
        }
       while(w1->next != NULL)
        {
            ListNode* w2 = w1->next;
            ListNode* w3 = w2;
            while(w3->next != NULL && w3->val == w1->val)
            {
                w3 = w3->next;
            }
            if(w3->next == NULL && w3->val == w1->val)
            {
                delete w1->next;
			    w1->next = NULL;
			    break;
            }
            w1->next = w3;
            w1 = w1->next;
        }
        return head;
    }
};
```