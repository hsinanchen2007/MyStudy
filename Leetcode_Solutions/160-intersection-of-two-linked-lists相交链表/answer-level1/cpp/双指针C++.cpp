### 解题思路
先遍历A链表算出一共多少个节点a+c=5, 遍历B链表算出一共多少个节点b+c=6，也就是B比A多一个节点，那么B先向后走一步就和A长度相等了，这个时候再同时每次向后移动一个节点，当指向相等的节点就是第一个公共节点了。

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
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        if(headA == headB)
            return headA;

        int countA = 1;
        ListNode* tempHead = headA;
        while(tempHead->next != nullptr)
        {
            countA++;
            tempHead = tempHead->next;
        }
        int countB = 1;
        tempHead = headB;
        while(tempHead->next != nullptr)
        {
            countB++;
            tempHead = tempHead->next;
        }
        while(countA > countB)
        {
            headA = headA->next;
            countA--;
        }
        while(countB > countA)
        {
            headB = headB->next;
            countB--;
        }
         while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```