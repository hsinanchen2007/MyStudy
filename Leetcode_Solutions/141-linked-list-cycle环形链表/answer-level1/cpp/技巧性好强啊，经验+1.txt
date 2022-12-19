### 解题思路
这种题感觉技巧性太强了，知道快慢指针就好了

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
        if(head==NULL) return false;
        //将快慢指针放到同一个起跑线
        ListNode *fast=head;//链表中的指针长得跟链表一样
        ListNode *slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;

        }
        return false;
    }
};
```