null--1--2--3--4--null
若某时刻：pre为1，cur为2，suc为3
调整策略：
1、cur指向suc的后继（2指向4）
2、suc指向cur（3指向2）
3、pre指向suc（1指向3）
null--1（pre）--3（suc）--2（cur）--4--null
更新策略：
1、pre更新为cur
2、cur更新为cur的后继
3、suc更新为cur的后继
null--1--3--2（pre）--4（cur）--null（suc）
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur && cur->next){
            ListNode* suc = cur->next;
            cur->next = suc->next;
            suc->next = cur;
            if(!pre) head = suc;
            else pre->next = suc;
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};
```
