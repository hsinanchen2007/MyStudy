1. 先遍历求得两个链表的长度，两个指针分别指向两个链表的头节点
2. 然后将长的那个链表的指针前移两个链表长度的差值个单位，这样就能抹消两个链表长度的差值
3. 再同时遍历两个列表，判断有无相同节点,如果有则直接return，无的话返回NULL
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
    ListNode *getCommonNode(ListNode *Long, ListNode *Short, int dif) {
        ListNode *tmpLong = Long, *tmpShort = Short;
        for (int i = 0; i < dif; i++) {
            tmpLong = tmpLong->next;
        }
        while (tmpLong != NULL) {
            if (tmpLong == tmpShort) {
                return tmpLong;
            }
            tmpLong = tmpLong->next;
            tmpShort = tmpShort->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int lengthA = 1, lengthB = 1;
        ListNode *tmp = headA;
        while (tmp != NULL) {
            tmp = tmp->next;
            lengthA++;
        }
        tmp = headB;
        while (tmp != NULL) {
            tmp = tmp->next;
            lengthB++;
        }
        ListNode *ans;
        if (lengthA > lengthB) {            
            int dif = lengthA - lengthB;
            ans = getCommonNode(headA, headB, dif);
        } else {
            int dif = lengthB - lengthA;
            ans = getCommonNode(headB, headA, dif);
        }
        return ans;
    }
};
```
