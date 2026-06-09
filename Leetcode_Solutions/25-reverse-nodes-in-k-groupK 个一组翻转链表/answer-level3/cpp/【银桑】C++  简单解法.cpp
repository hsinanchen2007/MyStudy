### 解题思路
![Screen Shot 2019-12-05 at 2.32.29 PM.png](https://pic.leetcode-cn.com/d9ce8b988087bf78182168390c0f45a2ecbfe103696cce512e904bf15d92c041-Screen%20Shot%202019-12-05%20at%202.32.29%20PM.png)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        if(head == NULL){
            return 0;
        }

        int length = 0;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        curr = head;
        if(length<k){
            return head;
        }
        else{   
            for(int i=0; i<k; ++i){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }         
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
    
};
```