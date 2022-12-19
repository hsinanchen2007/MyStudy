看了一圈发现C++的代码写的逻辑都不是很清楚，所以我就把自己的代码贴上来了。逻辑很清楚。具体的思路是双指针法。（如果不懂可以看官方的题解）。供大家参考！
```
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != nullptr){
            if(fast -> next == nullptr){
                fast = nullptr;
                break;
            }
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                break;
        }
        
        if(!fast)
            return nullptr;
        
        fast = head;
        while(fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};
```
