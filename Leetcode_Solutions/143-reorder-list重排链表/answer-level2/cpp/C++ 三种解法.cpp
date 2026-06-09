一，迭代，时间复杂度O(n^2)。
```
class Solution {
public:
    void reorderList(ListNode* head){
        helper(head);
    }
    ListNode* helper(ListNode* head){
        if(!head || !(head->next) || !(head->next->next)){return head;}
        ListNode* res=head;
        ListNode* p =head;
        ListNode* next = head->next;
        while(p->next){
            if(!(p->next->next)){
                break;
            }
            p = p->next;
        }
        head->next = p->next;
        p->next = nullptr;
        head = head->next;
        head->next = helper(next);
        return res;
    }
};
```
二，先遍历链表把节点加入vector，通过索引完成重新排序。时间复杂度O(n)。
```
class Solution {
public:
    void reorderList(ListNode* head){
        if(!head){return ;}
        vector<ListNode*> res;
        while(head){
            res.push_back(head);
            head = head->next;
        }
        int i = 0, j = res.size()-1;
        for(; i!=j; ++i, --j){
            res[i]->next = res[j];
            if(j == i+1){
                break;
            }
            res[j]->next = res[i+1];
        }
        res[j]->next = nullptr;
    }
};
```
三，先把链表分成前半段和后半段，把后半段逆序排列，再合并这两段。时间复杂度O(n)。
```
class Solution {
public:
    void reorderList(ListNode* head){
        if(!head){return ;}
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* preNode = nullptr;
        ListNode* p = slow->next;
        slow->next = nullptr;
        while(p){
            ListNode* next = p->next;
            p->next = preNode;
            preNode = p;
            p = next;
        }
        ListNode* res = new ListNode(-1);
        while(preNode){
            res->next = head;
            head = head->next;
            res = res->next;
            res->next = preNode;
            preNode = preNode->next;
            res = res->next;
        }
        res->next = head;
        head = res;
    }
};
```
