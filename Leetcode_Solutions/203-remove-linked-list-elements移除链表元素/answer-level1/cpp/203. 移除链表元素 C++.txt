### 解题思路
1.sential为哨兵，用于保护第一个结点。
2.pre指向移除元素结点的前驱结点，curr指向当前的需要移除的结点。
3.先将curr结点传toDelete结点，再将pre的next指针指向curr的next，将toDetele指针结点删除，并置为空。

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* prev = sentinel;
        ListNode* curr = head;
        ListNode* toDelete = NULL;
        while(curr != NULL){
            if(curr->val == val){
                prev->next = curr->next;
                toDelete = curr;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
            
            if(toDelete != NULL){
                delete toDelete;
                toDelete = NULL;
            }
        }
        
        ListNode* ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};
```