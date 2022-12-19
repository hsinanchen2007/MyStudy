### 解题思路
两个指针，sec指针先走k-1步，之后 head和sec一块走，直到 sec->next 为空

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* sec = head;
        k--;
        while(k)
        {
            sec = sec->next;
            if(sec==nullptr) return head;
            k--;
        }
        
        while(sec->next)
        {
            sec = sec->next;
            head = head->next;
        }
        return head;
    }
};
```