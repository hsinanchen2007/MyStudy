            最近老是用递归，导致看到题就想递归，说实话这道题使用递归并不简单，想要耍杂技的朋友可以试试
        整体思路分两步，第一步递归将链表中对应的数相加，第二步检查是否有进位，直接贴代码上来~
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list = func(l1,l2);
        check(list);
        return list;
    }
    
    ListNode* func(ListNode* l1, ListNode* l2){
        ListNode* list = new ListNode(0);
        if(!l1){
            list->val=l2->val;
            if(!l2->next)
                return list;
            else
                list->next = func(nullptr,l2->next);
        }
        if(!l2){
            list->val = l1->val;
            if(!l1->next)
                return list;
            else
                list->next = func(l1->next,nullptr);
        }
        if(l1&&l2){
            list->val = l1->val+l2->val;
            if(!l1->next&&!l2->next)
                return list;
        
        if(l1->next&&l2->next)
                list->next = func(l1->next,l2->next);
        else {
            if(!l1->next)
            list->next = func(nullptr,l2->next);
            if(!l2->next)
                list->next = func(l1->next,nullptr);
        }
        }

        return list;
    }
    void check(ListNode* list){
       if(list->next){
           if(list->val>=10){
               list->val-=10;
               list->next->val++;
           }
           check(list->next);
        }
        if(!list->next){
            if(list->val>=10){
                list->val-=10;
                list->next = new ListNode(1);
                return;
            }
        }
    }
};
```
    最麻烦的是两个数位数不相同，会多出很多分支。当两个数位数相同时，直接先加第一位，然后递归到底，如果两个数位数不同，则使用nullptr代替短的链表以便识别。
    检查是否溢出只要注意最高位的进位需要多创建一个节点就好了