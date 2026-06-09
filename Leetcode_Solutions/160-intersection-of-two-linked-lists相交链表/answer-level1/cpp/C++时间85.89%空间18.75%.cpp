基本思路与官方第三种解法类似，不同的是我先遍历两个链表记录下他们对应的长度len_a len_b，然后遍历的时候让长的链表的指针先走abs(len_a-len_b),这样保证如果相交时一定同时走到了相交的元素。
话说为什么我所有的C++解法空间都是最差的20%。。。
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        int len_a = 0, len_b = 0;
        ListNode* tmp_A = headA;
        ListNode* tmp_B = headB;
        for(;tmp_A!= nullptr;){
            len_a ++;
            tmp_A = tmp_A->next;
        }
        for(;tmp_B!= nullptr;){
            len_b ++;
            tmp_B = tmp_B->next;
        }
        while(headA != nullptr || headB != nullptr){
            if(len_a > len_b) {
                headA = headA->next;
                len_a--;
            }
            else if(len_a < len_b){
                headB = headB->next;
                len_b--;
            }
            else{
                if(headA == headB)
                    return headA;
                else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
        }
        return nullptr;
    }
};
```
