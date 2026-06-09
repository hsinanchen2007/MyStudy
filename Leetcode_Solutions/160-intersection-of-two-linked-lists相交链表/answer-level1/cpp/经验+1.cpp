### 解题思路
这个是看题解才明白的，嗯，比作两个人走路，我走你的路，你走我的路，路径相同终会相遇。。。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)  return NULL;
        ListNode *headA1=headA;
        ListNode *headB1=headB;
        while(headA1!=headB1){
            if(!headA1){
                headA1=headB;
            }
            else{
                headA1=headA1->next;
            }
            if(!headB1){
                headB1=headA;
            }
            else{
                headB1=headB1->next;
            }
        }
        return headA1;
    }
};
```