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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tNode = new ListNode(INT_MIN);
        tNode->next = head;
        ListNode *curNode = tNode->next;
        ListNode *lastNode = tNode;

        while(curNode){
            bool isEq = false;
            while(curNode->next && curNode->next->val == curNode->val){
                ListNode *tempNode = curNode->next;
                lastNode->next = tempNode;
                delete curNode;
                curNode = tempNode;
                isEq = true;

            }

            if(!isEq){
                lastNode->next = curNode;
                lastNode = curNode;
                curNode = curNode->next;
                
            } else {
                lastNode->next = curNode->next;
                curNode = curNode->next;
            }

        }
        return tNode->next;
        
    }
    
};
```