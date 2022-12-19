### 解题思路
方法一：快慢指针法

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
    bool hasCycle(ListNode *head) {
        //快慢指针
        ListNode *slow = head;
        ListNode *fast = head;
        
        // while(slow&&fast)
        while(fast)
        {
        slow=slow->next;//slow走一步
        fast=fast->next;//fast走两步
        if(!fast||!slow)
        {
           return false;
        }
           fast=fast->next;
           if(slow==fast)
           {
               return true;
           }
        }
        return false;    
    }
};
```