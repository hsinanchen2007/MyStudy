给定 1->2->3->4, 你应该返回 2->1->4->3.

### 解题思路
一共使用四个指针(三个功能性pre,n1,n2，一个类似tmp的next),只要pre->next,和pre->next->next一直有就一直遍历下去，每次遍历先把三个指针放好位置，再交换n1,n2,实际上就是让他们的->next换位置，最后给pre一个新的位置，以及新的指向，想让a的next指向b那么就a->next=b;

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
    ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(p->next && p->next->next){
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next=node2;
            p=p->next->next;
            
            
        }

        ListNode* retHead = dummyHead->next;
        delete dummyHead;

        return retHead;
    }
};
```