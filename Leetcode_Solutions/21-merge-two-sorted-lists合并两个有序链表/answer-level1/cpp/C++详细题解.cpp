### 解法1： 递归法
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1 -> val < l2 -> val){
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
        else{
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
};
```
### 解法2： 模拟排队 （迭代
想象：让两个队伍的小朋友自己根据从矮到高的原则排队。从两队的队首开始对比，由于时有序链表，若其中一队排列结束，另一队剩余的人直接接在整个队伍的后方。
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *begin = l1 -> val < l2 -> val ? l1 : l2;
        ListNode *ll1 = l1 -> val < l2 -> val ? l1 -> next : l1;
        ListNode *ll2 = l1 -> val < l2 -> val ? l2 : l2 -> next;
        ListNode *cur = begin;
        while(ll2){
            if(ll1 && ll1 -> val <= ll2 -> val){
                cur -> next = ll1;
                cur = cur -> next;
                ll1 = ll1 -> next;
            }
            else{
                cur -> next = ll2;
                cur = cur -> next;
                ll2 = ll2 -> next;
            }
        }
        if(ll1){
            cur -> next = ll1;
        }
        return begin;
    }
};
```
