### 解题思路
1. 思路
十分简单的思路，我使用两个指针遍历一次链表即可。
一个指针每次走两个节点，一个指针每次走一个节点。
当每次走两个节点的指针走到底时，每次走一步的指针便是结果。

2. 边界判断条件
在遍历循环中，如果走两步的指针的下一个节点为空，则说明整个链表的长度为奇数，直接返回当前的走一步的指针即可
在遍历循环中，如果走两步的指针的下两个节点为空，则说明整个链表的长度为偶数，则需要返回当前走一步指针的下一个节点。

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
    ListNode* middleNode(ListNode* head) {
        if(NULL == head){
            return NULL;
        }
        ListNode *p1,*p2;
        int count = 0;
        p1 = head; p2 = head;
        while(p2 != NULL){
            if(p2->next == NULL){
                return p1;
            }else if(p2->next->next == NULL){
                return p1->next;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
};
```