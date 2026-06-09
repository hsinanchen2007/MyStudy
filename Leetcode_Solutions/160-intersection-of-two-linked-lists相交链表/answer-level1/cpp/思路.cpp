### 解题思路
蛮巧妙的，比不同起点的方法要简洁 简单很多

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
      if(!headA || !headB)  return NULL;
      ListNode* pA = headA;
      ListNode* pB = headB;
      /*
      A链表长度x, B长度y，如果没有相交，那x + y = y + x，最后pA == pB == NULL，return NULL
      A链表长度x, B长度y, 如果相交的地方离A起点为 a , 离B起点为 b, 他们到结尾的长度都肯定是一样的为c
      那等于 a + c + b  =  b + c + a，所以相遇的点，一定就是相遇点，这个还是很巧妙的 
      */
      while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
      }
      return pA;
    }
};
```