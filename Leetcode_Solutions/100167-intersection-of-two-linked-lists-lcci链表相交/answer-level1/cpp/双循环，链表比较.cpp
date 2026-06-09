### 解题思路
构建两个循环，判断链表是否相等即可

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
    //双循环即可
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode* temp = headB;
            while(temp){
                if(headA == temp) return headA;
                else{
                    temp = temp->next;
                }
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
```