### 解题思路
此处撰写解题思路
一开始使用hashmap来存放节点指针值，通过查找匹配来判定是否是环形链表，效率比较低下。
看了各位大神的解法之后，使用了快慢指针，重新写了一遍，效率提高了，空间复杂度也降低了，学到了
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
       if(head == nullptr || head->next == nullptr)
            return false;

        ListNode *slow = head->next;
        ListNode *quick = head->next->next;

        while(quick && quick->next){
            if(quick == slow)
                return true;
            else{
                quick = quick->next->next;
                slow = slow->next;
            }
        }

        return false;
    }
};
```