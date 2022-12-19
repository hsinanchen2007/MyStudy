```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 遇见重复的立马就删
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL)
            return NULL;

        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode * pre = dummyHead;  //设立3个指针，pre,cur,next
        ListNode * cur = head;
        ListNode * next = head->next;   
        bool FLAG = false;      //flag 遇见重复的元素变true   cur->val == next->val
        while (next) {
            if (cur->val == next->val) {  //cur和next的val相同，删除next节点，新next指向旧next的下一个，cur的下一个是新next
                FLAG = true;
                cur->next = next->next;
                delete next;
                next = cur->next;
            }
            else {  //val不同时，三个指针向后依次挪动
                pre = cur;
                cur = next;
                next = next->next;
            }

            if (FLAG && next && cur->val != next->val) {  //遇见了重复元素，同时next还没到NULL，next和cur的val不相等
                FLAG = false;                              //说明此时next已经移出了连续相同元素的范围，指向了新的值
                pre->next = next;                           //可以删除cur节点了
                delete cur;
                cur = next;
                next = next->next;
            }
            if (FLAG && !next ) {       // 遇见了重复元素，同时next移动到了NULL，说明从cur已经是尾节点了，直接删除cur
                pre->next = NULL;       // 让pre指向NULL
                delete cur;
                }
            // }
        }
        ListNode * ret = dummyHead->next;
        delete dummyHead;
        return ret;
        
    }
};
```