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

    ListNode* sortList(ListNode* head) {

        if(!head || !head->next) {
            return head;
        }
        if(head->next->next == NULL){
            if (head->val > head->next->val){
                ListNode* temp = head->next;
                head->next = NULL;
                temp->next = head;
                return temp;
            } else {
                return head;
            }
        }
        ListNode* f = head;
        ListNode* s = head;
        while (f->next) {
            f = f->next;
            if(f->next) {
                f = f->next;
                s = s->next;
            }
        }
        ListNode* right = s->next;
        s->next = NULL;
    
        return Merge(sortList(head), sortList(right));
    }

    
    ListNode* Merge(ListNode* leftSide, ListNode* rightSide)
    {
        ListNode* pHead = new ListNode(INT_MIN);
        ListNode* ptr = pHead;
        
        while (leftSide && rightSide) {
            if(leftSide->val < rightSide->val) {
                ptr->next = leftSide;
                leftSide = leftSide->next;
            } else {
                ptr->next = rightSide;
                rightSide = rightSide->next;
            }
            ptr = ptr->next;
        }
        if (leftSide) {
            ptr->next = leftSide;
        }
        if (rightSide) {
            ptr->next = rightSide;
        }
        
        return pHead->next;
    }
};
```