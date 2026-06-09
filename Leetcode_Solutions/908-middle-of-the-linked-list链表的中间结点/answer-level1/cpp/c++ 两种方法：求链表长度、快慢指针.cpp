


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
/**************************方法2：快慢指针*******************/
    ListNode* middleNode(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast != NULL && fast->next != NULL)
       {
           fast = fast->next->next;
           slow = slow->next;
       }
       return slow;
    }
};
/*************************方法1：求取链表长度******************
ListNode* middleNode(ListNode* head) {
        int len = 0,mid = 0;
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            len++;
            tmp = tmp->next;
        }
        mid = len/2; //无论len是奇数还是偶数，
        tmp = head;
        while(mid>0)
        {
            tmp = tmp->next;
            mid--;
        }
        return tmp;
    }
*/
```